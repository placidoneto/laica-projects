void frontIClockservo(){ // gira face da frente do cubo no sentido anti-horário
  empurrar();
  tempo();
  empurrar();
  tempo();
  empurrar();
  tempo();
  agarrar();
  tempo();
  base_garra();
  tempo();
  voltar();
  ajuste();
  tempo();
  empurrar();}

void frontClockservo(){ // gira face da frente do cubo no sentido horário
  empurrar();
  tempo();
  empurrar();
  tempo();
  empurrar();
  tempo();
  agarrar();
  tempo();
  base_garra();
  tempo();
  base_garra();
  tempo();
  base_garra();
  tempo();
  voltar();
  ajuste();
  tempo();
  empurrar();}

 void frontClock180servo(){ // gira face da frente do cubo 180 graus
  empurrar();
  tempo();
  empurrar();
  tempo();
  empurrar();
  tempo();
  agarrar();
  tempo();
  base_garra();
  tempo();
  base_garra();
  tempo();
  voltar();
  ajuste();
  tempo();
  empurrar();}
  
void leftIClockservo(){ // gira face da esquerda do cubo no sentido anti-horário
  base_livre();
  tempo();
  base_livre();
  tempo();
  base_livre();
  tempo();
  empurrar();
  tempo();
  empurrar();
  tempo();
  empurrar();
  tempo();
  agarrar();
  tempo();
  base_garra();
  tempo();
  voltar();
  ajuste();
  tempo();
  empurrar();
  base_livre();
  tempo();}
  
void leftClockservo(){ // gira face da esquerda do cubo no sentido horário
  base_livre();
  tempo();
  base_livre();
  tempo();
  base_livre();
  tempo();
  empurrar();
  tempo();
  empurrar();
  tempo();
  empurrar();
  tempo();
  agarrar();
  tempo();
  base_garra();
  tempo();
  base_garra();
  tempo();
  base_garra();
  tempo();
  voltar();
  ajuste();
  tempo();
  empurrar();
  base_livre();
  tempo();}
  
void leftClock180servo(){ // gira face da esquerda do cubo 180 graus
  base_livre();
  tempo();
  base_livre();
  tempo();
  base_livre();
  tempo();
  empurrar();
  tempo();
  empurrar();
  tempo();
  empurrar();
  tempo();
  agarrar();
  tempo();
  base_garra();
  tempo();
  base_garra();
  tempo();
  voltar();
  ajuste();
  tempo();
  empurrar();
  base_livre();
  tempo();}
  
void rightIClockservo(){ // gira face da direita do cubo no sentido anti-horário
  base_livre();
  tempo();  
  empurrar();
  tempo();
  empurrar();
  tempo();
  empurrar();
  tempo();
  agarrar();
  tempo();
  base_garra();
  tempo();  
  voltar();
  ajuste();
  tempo();
  empurrar();
  tempo();
  base_livre();
  tempo();
  base_livre();
  tempo();
  base_livre();
  tempo();}
  
void rightClockservo(){ // gira face da direita do cubo no sentido horário 
  base_livre();
  tempo();
  tempo();  
  empurrar();
  tempo();
  empurrar();
  tempo();
  empurrar();
  tempo();
  agarrar();
  tempo();
  base_garra();
  tempo();
  base_garra();
  tempo();
  base_garra();
  tempo();  
  voltar();
  ajuste();
  tempo();
  empurrar();
  tempo();
  base_livre();
  tempo();
  base_livre();
  tempo();
  base_livre();
  tempo();}
  
void rightClock180servo(){ // gira face da direita do cubo 180 graus
  base_livre();
  tempo();
  tempo();  
  empurrar();
  tempo();
  empurrar();
  tempo();
  empurrar();
  tempo();
  agarrar();
  tempo();
  base_garra();
  tempo();
  base_garra();
  tempo();  
  voltar();
  ajuste();
  tempo();
  empurrar();
  base_livre();
  tempo();
  base_livre();
  tempo();
  base_livre();
  tempo();}
  
void bottomIClockservo(){ // gira face de debaixo do cubo no sentido anti-horário
  agarrar();
  tempo();
  base_garra();
  tempo();
  voltar();
  tempo();
  ajuste();}
  
void bottomClockservo(){ // gira face de debaixo do cubo no sentido horário
  agarrar();
  tempo();
  base_garra();
  tempo();
  base_garra();
  tempo();
  base_garra();
  tempo();
  voltar();
  ajuste();}
  
void bottomClock180servo(){ // gira face de baixo do cubo 180 graus
  agarrar();
  tempo();
  base_garra();
  tempo();
  base_garra();
  tempo();
  voltar();
  ajuste();}
  
void backIClockservo(){ // gira face de trás do cubo no sentido anti-horário
  empurrar();
  tempo();
  agarrar();
  tempo();
  base_garra();
  tempo();
  voltar();
  ajuste();
  empurrar();
  tempo();
  empurrar();
  tempo();
  empurrar();}
  
void backClockservo(){ // gira face de trás do cubo no sentido horário
  empurrar();
  tempo();
  agarrar();
  tempo();
  base_garra();
  tempo();
  base_garra();
  tempo();
  base_garra();
  tempo();  
  voltar();
  tempo(); 
  ajuste();
  empurrar();
  tempo();
  empurrar();
  tempo();
  empurrar();
  tempo();}
  
void backClock180servo(){ // gira face de trás do cubo 180 graus
  empurrar();
  tempo();
  agarrar();
  tempo();
  base_garra();
  tempo();
  base_garra();
  tempo();
  voltar();
  ajuste();
  empurrar();
  tempo();
  empurrar();
  tempo();
  empurrar();
  tempo();}
  
void topIClockservo(){ // gira face de cima do cubo no sentido anti-horário
  empurrar();
  tempo();
  empurrar();
  tempo();
  agarrar();
  tempo();
  base_garra();
  tempo();
  voltar();
  ajuste();
  tempo();
  empurrar();
  tempo();
  empurrar();}
  
void topClockservo(){ // gira face de cima do cubo no sentido horário
  empurrar();
  tempo();
  empurrar();
  tempo();
  agarrar();
  tempo();
  base_garra();
  tempo();
  base_garra();
  tempo();
  base_garra();
  tempo();
  voltar();
  ajuste();
  tempo();
  empurrar();
  tempo();
  empurrar();}
  
void topClock180servo(){ // gira face de cima do cubo 180 graus
  empurrar();
  tempo();
  empurrar();
  tempo();
  agarrar();
  tempo();
  base_garra();
  tempo();
  base_garra();
  tempo();
  voltar();
  ajuste();
  tempo();
  empurrar();
  tempo();
  empurrar();}
