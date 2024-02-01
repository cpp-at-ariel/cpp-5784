#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"

int main(int argc, char** argv) {
    /* See here https://github.com/onqtam/doctest/blob/master/doc/markdown/main.md for more options */
    doctest::Context context;
    context.addFilter("reporters", "console");   // options: "console", "xml", "empty", "grader"
    //context.addFilter("reporters", "grader");   // options: "console", "xml", "empty", "grader"
    context.run();  // returns 0 if all tests passed; otherwise returns 1.
}
