# taschenrechner
sujan, leonat, daniel, fabian

# IPERKA

## planung
sujan: +, design

leonat: präsi, *, /

daniel: -, dokumentation

fabian: klammern, funktionen


## funktionsweise

### expression
Bei unserem rechner wird eine Rechnung als ein array von Expressions (=Ausdrücke) dargestellt.
Jeder ausdruck ist ein bestimmter teil einer rechnung. 

Zum beispiel bei der rechnung 77+100 hat es 3 expressions: 77; +; 100;

Dabei gibt es verschiedene arten von Expressions. Es gibt zahlen, operatoren (+, -, etc), klammern und
spezielle funktionen (wie fact() oder sin())

### sub expression parser
der Subexpression parser teilt eine Rechnung in ihre (sub-)Expressions auf.

###