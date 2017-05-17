void parar(){ //para o motor ligado a L298N
  analogWrite(ena, 255);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, HIGH);}
   
void servo90graus(){ //coloca a garra na posição inicial
  digitalWrite(servo_garra, HIGH);
  delayMicroseconds(1200);
  digitalWrite(servo_garra, LOW);
  for(int i = 0; i<15; i++) delayMicroseconds(1200);}

void servo50graus(){ //coloca a garra na posição de segurar o cubo
  digitalWrite(servo_garra, HIGH);
  delayMicroseconds(930);
  digitalWrite(servo_garra, LOW);
  for(int i = 0; i<20; i++) delayMicroseconds(930);}
  
void servo20graus(){ //coloca a garra na posição de empurar o cubo
  digitalWrite(servo_garra, HIGH);
  delayMicroseconds(760);
  digitalWrite(servo_garra, LOW);
  for(int i = 0; i<25; i++) delayMicroseconds(760);}
  
void anda_90livre(){ //faz base do cubo girar 90 graus no sentido horário quando a garra está na posição inicial 
  pulso = digitalRead(pino_D0); 
  while (pulso == 1 && fim_movimento == 1) {
  analogWrite(ena, 55);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);  
  pulso = digitalRead(pino_D0);}
  parar();
  delay(20);
  analogWrite(ena, 50);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);  
  delay(54);
  parar();
  fim_movimento = 0;
  delay(500);}

void anda_90garra(){ //faz base do cubo girar 90 graus no sentido horário quando a garra está na posição de segurar o cubo  
  pulso = digitalRead(pino_D0);
  while (pulso == 1 && fim_movimento == 1) {
  analogWrite(ena, 60);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);  
  pulso = digitalRead(pino_D0);}
  parar();
  delay(20);}
 
void servo_ajuste_Fechar(){ //faz o servo de ajuste fechar
  digitalWrite(servo_ajuste, HIGH);
  delayMicroseconds(900);
  digitalWrite(servo_ajuste, LOW);
  for(int i = 0; i<2; i++) delayMicroseconds(900);}
  
void servo_ajuste_Abrir(){ //faz o servo de ajuste abrir
  digitalWrite(servo_ajuste, HIGH);  //pulso do servo
  delayMicroseconds(2400);     //2.4ms
  digitalWrite(servo_ajuste, LOW);   //completa periodo do servo
  for(int i=0;i<7;i++)delayMicroseconds(1400);}

void tempo(){delay(200);} //Tempo padrão entre a execução de funções de movimento 

void empurrar(){ //faz o movimento para empurrar o cubo 
  for(char i = 0; i < 30; i++)  servo20graus();
  for(char i = 0; i < 30; i++)  servo90graus();}
  
void agarrar(){ //faz o movimento para segurar o cubo 
  for(char i = 0; i < 30; i++)  servo50graus();}
  
void ajuste(){ //faz o movimento para ajustar o cubo 
  for(char i=0;i<100;i++)servo_ajuste_Fechar();
  for(char i=0;i<100;i++) servo_ajuste_Abrir();}

void voltar(){ //coloca servo na posição inicial 
  for(char i = 0; i < 30; i++)  servo90graus();}

void base_livre(){ //gira base do cubo livre 
  fim_movimento = 1;
  anda_90livre();}

void base_garra(){ //gira base do cubo com a garra 
  fim_movimento = 1;
  anda_90garra();}
  
void inicio(){
  Serial.println("INICIANDO.....");
  ajuste();
  tempo();
  ajuste();
  tempo();
  Serial.println("PRONTO!");
  Serial.println("Digite uma tecla:");} 

