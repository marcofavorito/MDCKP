TEX = pdflatex -shell-escape -interaction=nonstopmode -file-line-error
BIB = bibtex

.PHONY: all

all : main.pdf

main.pdf : main.tex main.bbl main.blg
	$(TEX) main.tex

main.bbl main.blg : main.bib main.aux
	$(BIB) main

main.aux : main.tex
	$(TEX) main.tex

main.bib : main.tex
	$(TEX) main.tex

clean:
	rm -f *.aux *.bbl *.blg *-blx.bib *.log *.run.xml *.synctex.gz