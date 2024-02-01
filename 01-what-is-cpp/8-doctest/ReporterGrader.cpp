/*
   Example from here:
   https://github.com/onqtam/doctest/blob/master/doc/markdown/reporters.md
*/

#include "doctest.h"
#include <iostream>
using namespace doctest;

std::ostream& file_line_to_stream(std::ostream& s, const char* file, int line,
                                    const char* tail = "") {
    const auto opt = getContextOptions();
    s << Color::LightGrey << skipPathFromFilename(file) << (opt->gnu_file_line ? ":" : "(")
        << (opt->no_line_numbers ? 0 : line) // 0 or the real num depending on the option
        << (opt->gnu_file_line ? ":" : "):") << tail;
    return s;
}


struct ReporterGrader: public IReporter {
    // caching pointers/references to objects of these types - safe to do
    std::ostream&         stdout_stream;
    const ContextOptions& options;
    const TestCaseData*   test_case_data;

    // constructor has to accept the ContextOptions by ref as a single argument
    ReporterGrader(const ContextOptions& input_options)
            : stdout_stream(*input_options.cout)
            , options(input_options) {}

    void report_query(const QueryData& /*in*/) override {}
    void test_run_start() override {}
    void test_run_end(const TestRunStats& run_stats) override {
        // std::cout << run_stats.numTestCasesFailed << " " << " out of " << run_stats.numTestCasesPassingFilters << " tests failed" << std::endl;
        // std::cout << run_stats.numAssertsFailed << " " << " out of " << run_stats.numAsserts << " asserts failed" << std::endl;
        float grade = (run_stats.numAsserts - run_stats.numAssertsFailed) * 100 / run_stats.numAsserts;
        std::cout << "[doctest] Your grade is " << grade << std::endl;
    }
    void test_case_start(const TestCaseData& input_data) override { test_case_data = &input_data; }
    void test_case_reenter(const TestCaseData& /*in*/) override {}
    void test_case_end(const CurrentTestCaseStats& /*in*/) override {}
    void test_case_exception(const TestCaseException& /*in*/) override {}
    void subcase_start(const SubcaseSignature& /*in*/) override {}
    void subcase_end() override { }
    void log_assert(const AssertData& rb) override {  }
    void log_message(const MessageData& /*in*/) override {}
    void test_case_skipped(const TestCaseData& /*in*/) override {}
};

// "1" is the priority - used for ordering when multiple reporters are used
REGISTER_REPORTER("grader", 1, ReporterGrader);

// registering the same class as a reporter and as a listener is nonsense but it's possible
// REGISTER_LISTENER("my_listener", 1, MyXmlReporter);