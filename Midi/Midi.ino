#include <MIDI.h>
#include <Midiant.h>

MIDI_CREATE_DEFAULT_INSTANCE();

//Entrada do arduíno dos botões e potenciômetro
int btns[] = {2, 3, 4, 5, 6, 7};
int pots[] = {A0};

//Quantidade dos equipamentos
int tamBtn = (sizeof(btns) / 2);
int tamPot = (sizeof(pots) / 2);
//Não alterar
int somaNotas = 0;
int canal = 1;
Midiant *a[(sizeof(btns) / 2)];

void setup()
{
  Serial.begin(115200);

  for (int i = 0; i < tamBtn; i++)
  {
    (i < tamPot)?a[i] = new Midiant(btns[i], pots[i]):a[i] = new Midiant(btns[i]);
  }
}

void loop()
{
  for (int i = 0; i < tamBtn; i++)
  {
    somaNotas = i;
    if (i == 5)
    {
      if (canal == 1)
        a[i]->BtnCB([]()
                  { canal = 2; });
      if (canal == 2)
        a[i]->BtnCB([]()
                  { canal = 3; });
      if (canal == 3)
        a[i]->BtnCB([]()
                  { canal = 1; });
    }
    a[i]->Btn(Som);
  }

  for (int i = 0; i < tamPot; i++)
  {
    a[i]->Pot(Pot);
  }

}

void Som(int i)
{
  if(i ==1)MIDI.sendNoteOn(36 + somaNotas, 127, canal);
  if(i==2)MIDI.sendNoteOff(36 + somaNotas, 0, canal);
  
  
}

void Pot(int midiPot)
{

  MIDI.sendControlChange(176, midiPot, canal);
}