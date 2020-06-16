int i=0;
void setup()
{
  for(i=0;i<10;i++)
  {
  pinMode(i, OUTPUT);
    pinMode(i+1, OUTPUT);
  }
}

void loop()
{
  for(i=0;i<10;i++)
  {
  digitalWrite(i, HIGH);
    digitalWrite(i+1, HIGH);
  delay(300); // Wait for 1000 millisecond(s)
  digitalWrite(i, LOW);
    digitalWrite(i+1, LOW);
  delay(300); // Wait for 1000 millisecond(s)
  }
}