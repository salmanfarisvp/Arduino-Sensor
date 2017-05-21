 char input;  
  
void setup() 
{  
  Serial.begin(9600);  
  pinMode(LED, OUTPUT);  
  Serial.println(">> START<<");  
}  
  
void loop() 
{  
  if(Serial.available()>0)  
  {  
    input= Serial.read(); 
    Serial.println(input);
    
  }  
    
}  
