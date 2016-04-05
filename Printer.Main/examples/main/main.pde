#include <PrinterMainClass.h>
PrinterMain printer;
void setup() {
  printer.init();
}
void loop() {
  printer.main();
}