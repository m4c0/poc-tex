all:
	tex -ini empty.tex
	tex -file-line-error -fmt=empty hello.tex
	dvipdfm hello.dvi

