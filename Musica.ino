#define REST      0
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988

// ---------------------- 2. CONFIGURAÇÕES ---------------------------
// Defina o pino onde o buzzer está conectado
int buzzerPin = 8;

// Ajuste a velocidade da música (BPM - Batidas Por Minuto)
int songSpeed = 200;

// ---------------------------------------------------------------------
//    ESBOÇO DA MÚSICA - COLOQUE SUAS NOTAS E DURAÇÕES AQUI
// ---------------------------------------------------------------------
// Exemplo: "Brilha, Brilha, Estrelinha"

// Array da melodia: as notas que serão tocadas
int melody[] = {
  NOTE_C4, NOTE_C4, NOTE_G4, NOTE_G4, NOTE_A4, NOTE_A4, NOTE_G4,
  NOTE_F4, NOTE_F4, NOTE_E4, NOTE_E4, NOTE_D4, NOTE_D4, NOTE_C4,
  
  NOTE_C4, NOTE_CS4, NOTE_D4, NOTE_DS4, NOTE_E4, NOTE_F4, NOTE_FS4,
  NOTE_G4, NOTE_GS4, NOTE_A4, NOTE_AS4, NOTE_B4, NOTE_C5, NOTE_CS5, 
  NOTE_D5, NOTE_DS5, NOTE_E5, NOTE_F5, NOTE_FS5, NOTE_G5, NOTE_GS5,
  NOTE_A5, NOTE_AS5, NOTE_B5
};

// Array das durações: o tempo de cada nota
// 4 = Semínima (um tempo)
// 8 = Colcheia (meio tempo)
// 2 = Mínima (dois tempos)
// 1 = Semibreve (quatro tempos)
// (Valores negativos, ex: -4, indicam uma nota pontuada)
int noteDurations[] = {
  4, 4, 4, 4, 4, 4, 2,
  4, 4, 4, 4, 4, 4, 1,
  
  8, 8, 8, 8, 8, 8, 8,
  8, 8, 8, 8, 8, 8, 8,
  8, 8, 8, 8, 8, 8, 8,
  8, 8, 1
};
// ---------------------------------------------------------------------
//                 FIM DO ESBOÇO DA MÚSICA
// ---------------------------------------------------------------------


void setup() {
  // Calcula a duração de uma "semínima" (quarter note) em milissegundos
  // 60.000 ms (1 minuto) / BPM
  int quarterNoteDuration = (60000 / songSpeed);

  // Calcula o tamanho total da música (quantas notas tem)
  int songLength = sizeof(melody) / sizeof(melody[0]);

  // Itera sobre cada nota da música
  for (int thisNote = 0; thisNote < songLength; thisNote++) {
    
    // Calcula a duração da nota atual em milissegundos
    // Ex: Se 4 = 500ms, 8 = 250ms, 2 = 1000ms
    int noteDuration = (quarterNoteDuration * 4) / noteDurations[thisNote];

    // Toca a nota
    // A função tone() toca a frequência (melody[thisNote])
    // no pino (buzzerPin) pela duração (noteDuration)
    tone(buzzerPin, melody[thisNote], noteDuration);

    // Pausa entre as notas para que não fiquem grudadas
    // (Pausa 30% maior que a duração da nota para dar tempo de tocar + silêncio)
    // Ajuste esse multiplicador (ex: 1.3) se quiser mais ou menos espaço
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    
    // Para a nota (opcional, mas bom para notas distintas)
    noTone(buzzerPin);
  }
}

void loop() {
  // O setup() toca a música uma vez.
  // Deixe o loop() vazio para não repetir.
  // Se quiser que a música toque continuamente, mova o código do setup() para cá.
}