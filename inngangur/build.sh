#!/usr/bin/env bash
if [ $# == 0 ]
then
	echo "Argument required"
	exit
fi
pdflatex -output-directory output $1
mv output/$(basename $1 .tex).pdf ./pdf
