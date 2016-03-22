//-------------------------------------------------
//  Voltimeter using Arduino and 7 Segments Display
//  Developed by Caio Luiz Gomes
//  Email: caio.alves at cear.ufpb.br
//-------------------------------------------------

// DEFINE
#define r1       1000000;
#define r2       100000;
#define aRef     5;
#define time_ref 500;

// Global variable
float voltage;
unsigned long millis_ref = 0;

// Voltage Function
float voltage_func(int a_read_v){
	return (analogRead(a_read_v)*aRef) / 1023.0 * ((r1+r2)/r2);
}

// Ammeter Function
float amper_func(int a_read_i){
	
}
void setup(){
}

void loop(){
	if((millis()-millis_ref) > time_ref) {
	voltage = voltage_func(A1);
	millis_ref = millis();
	}
	float v = voltage;

	//Falta mostrar o valor da tensão
}