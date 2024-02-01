#!/usr/bin/make -f
# A makefile for building pdf files from the text (odt files) and slides (odp files).
# Author: Erel Segal-Halevi
# Since: 2019-02

SOURCES_ODP=$(shell find . -name '*.odp')
TARGETS_ODP=$(subst .odp,.pdf,$(SOURCES_ODP))
SOURCES_ODT=$(shell find . -name '*.odt')
TARGETS_ODT=$(subst .odt,.pdf,$(SOURCES_ODT))
SOURCES_DOC=$(shell find . -name '*.doc*')
TARGETS_DOC=$(subst .doc,.pdf,$(subst .docx,.pdf,$(SOURCES_DOC)))
SOURCES_ODS=$(shell find . -name '*.ods')
TARGETS_XSLX=$(subst .ods,.xlsx,$(SOURCES_ODS))

all: $(TARGETS_ODP) $(TARGETS_ODT) $(TARGETS_DOC) $(TARGETS_XSLX)
	#
	git commit -m "update pdf and xslx files"
	git push
	echo Done!
	sleep 86400

%.pdf: %.odt
	#
	libreoffice --headless --convert-to pdf $< --outdir $(@D)
	git add $@
	git add $<
	
%.pdf: %.doc*
	#
	libreoffice --headless --convert-to pdf $< --outdir $(@D)
	git add $@
	git add $<

%.pdf: %.odp
	#
	libreoffice --headless --convert-to pdf $< --outdir $(@D)
	git add $@
	git add $<

%.xlsx: %.ods
	#
	libreoffice --headless --convert-to xlsx $< --outdir $(@D)
	git add $@
	git add $<

clean:
	rm -f *.pdf
