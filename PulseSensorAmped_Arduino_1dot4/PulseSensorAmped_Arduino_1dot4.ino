/* This code was originally found on http://www.pulsesensor.com and 
http://playground.arduino.cc/ComponentLib/Thermistor. , then modified by our team*/

/*  Pulse Sensor Amped 1.4    by Joel Murphy and Yury Gitman   http://www.pulsesensor.com

----------------------  Notes ----------------------  ---------------------- 
This code:
1) Blinks an LED to User's Live Heartbeat   PIN 13
2) Fades an LED to User's Live HeartBeat
3) Determines BPM
4) Prints All of the Above to Serial

Read Me:
https://github.com/WorldFamousElectronics/PulseSensor_Amped_Arduino/blob/master/README.md   
 ----------------------       ----------------------  ----------------------
*/

#include <Arduino.h>
#include <avr/pgmspace.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd (8,9,4,5,6,7);

byte degree[8] = {
  B00100,
  B01010,
  B00100,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000};

const int temps[] PROGMEM = { 0, 1, 2, 3, 4, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 143, 144, 145, 146, 147, 148, 149, 150, 151, 151, 152, 153, 154, 155, 156, 157, 158, 159, 159, 160, 161, 162, 163, 164, 165, 166, 167, 167, 168, 169, 170, 171, 172, 173, 174, 175, 175, 176, 177, 178, 179, 180, 181, 182, 182, 183, 184, 185, 186, 187, 188, 189, 190, 190, 191, 192, 193, 194, 195, 196, 197, 197, 198, 199, 200, 201, 202, 203, 204, 205, 205, 206, 207, 208, 209, 210, 211, 212, 212, 213, 214, 215, 216, 217, 218, 219, 220, 220, 221, 222, 223, 224, 225, 226, 227, 228, 228, 229, 230, 231, 232, 233, 234, 235, 235, 236, 237, 238, 239, 240, 241, 242, 243, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 252, 253, 254, 255, 256, 257, 258, 259, 260, 260, 261, 262, 263, 264, 265, 266, 267, 268, 269, 269, 270, 271, 272, 273, 274, 275, 276, 277, 278, 279, 279, 280, 281, 282, 283, 284, 285, 286, 287, 288, 289, 289, 290, 291, 292, 293, 294, 295, 296, 297, 298, 299, 300, 301, 301, 302, 303, 304, 305, 306, 307, 308, 309, 310, 311, 312, 313, 314, 315, 315, 316, 317, 318, 319, 320, 321, 322, 323, 324, 325, 326, 327, 328, 329, 330, 331, 332, 333, 334, 335, 335, 336, 337, 338, 339, 340, 341, 342, 343, 344, 345, 346, 347, 348, 349, 350, 351, 352, 353, 354, 355, 356, 357, 358, 359, 360, 361, 362, 363, 364, 365, 366, 367, 368, 369, 370, 371, 372, 373, 374, 375, 376, 377, 378, 379, 380, 381, 382, 383, 384, 385, 386, 387, 388, 389, 390, 392, 393, 394, 395, 396, 397, 398, 399, 400, 401, 402, 403, 404, 405, 406, 407, 408, 410, 411, 412, 413, 414, 415, 416, 417, 418, 419, 420, 422, 423, 424, 425, 426, 427, 428, 429, 430, 432, 433, 434, 435, 436, 437, 438, 439, 441, 442, 443, 444, 445, 446, 448, 449, 450, 451, 452, 453, 455, 456, 457, 458, 459, 460, 462, 463, 464, 465, 466, 468, 469, 470, 471, 472, 474, 475, 476, 477, 479, 480, 481, 482, 484, 485, 486, 487, 489, 490, 491, 492, 494, 495, 496, 498, 499, 500, 501, 503, 504, 505, 507, 508, 509, 511, 512, 513, 515, 516, 517, 519, 520, 521, 523, 524, 525, 527, 528, 530, 531, 532, 534, 535, 537, 538, 539, 541, 542, 544, 545, 547, 548, 550, 551, 552, 554, 555, 557, 558, 560, 561, 563, 564, 566, 567, 569, 570, 572, 574, 575, 577, 578, 580, 581, 583, 585, 586, 588, 589, 591, 593, 594, 596, 598, 599, 601, 603, 604, 606, 608, 609, 611, 613, 614, 616, 618, 620, 621, 623, 625, 627, 628, 630, 632, 634, 636, 638, 639, 641, 643, 645, 647, 649, 651, 653, 654, 656, 658, 660, 662, 664, 666, 668, 670, 672, 674, 676, 678, 680, 683, 685, 687, 689, 691, 693, 695, 697, 700, 702, 704, 706, 708, 711, 713, 715, 718, 720, 722, 725, 727, 729, 732, 734, 737, 739, 741, 744, 746, 749, 752, 754, 757, 759, 762, 764, 767, 770, 773, 775, 778, 781, 784, 786, 789, 792, 795, 798, 801, 804, 807, 810, 813, 816, 819, 822, 825, 829, 832, 835, 838, 842, 845, 848, 852, 855, 859, 862, 866, 869, 873, 877, 881, 884, 888, 892, 896, 900, 904, 908, 912, 916, 920, 925, 929, 933, 938, 942, 947, 952, 956, 961, 966, 971, 976, 981, 986, 991, 997, 1002, 1007, 1013, 1019, 1024, 1030, 1036, 1042, 1049, 1055, 1061, 1068, 1075, 1082, 1088, 1096, 1103, 1110, 1118, 1126, 1134, 1142, 1150, 1159, 1168, 1177, 1186, 1196, 1206, 1216, 1226, 1237, 1248, 1260, 1272, 1284, 1297, 1310, 1324, 1338, 1353, 1369, 1385, 1402, 1420, 1439, 1459, 1480, 1502 };

//  Variables
int btnInput = 0;
int pulsePin = 1;                 // Pulse Sensor purple wire connected to analog pin 0
int blinkPin = 13;                // pin to blink led at each beat
int fadePin = 5;                  // pin to do fancy classy fading blink at each beat
int fadeRate = 0;                 // used to fade LED on with PWM on fadePin

// Volatile Variables, used in the interrupt service routine!
volatile int BPM;                   // int that holds raw Analog in 0. updated every 2mS
volatile int Signal;                // holds the incoming raw data
volatile int IBI = 600;             // int that holds the time interval between beats! Must be seeded! 
volatile boolean Pulse = false;     // "True" when User's live heartbeat is detected. "False" when not a "live beat". 
volatile boolean QS = false;        // becomes true when Arduoino finds a beat.

// Regards Serial OutPut  -- Set This Up to your needs
static boolean serialVisual = true;   // Set to 'false' by Default.  Re-set to 'true' to see Arduino Serial Monitor ASCII Visual Pulse 


void setup(){
  lcd.begin(16,2);
  lcd.print("Temperature");
  lcd.createChar(0, degree);
  
  btnInput = analogRead(0);
  while(btnInput < 500 || btnInput > 800){
    lcd.setCursor(0,1);
    lcd.print("                ");
    
    int temp = analogRead(8) - 238;
    temp = pgm_read_word(&temps[temp]);
    
    int beforeDecimal= temp / 10;
    int afterDecimal = temp - beforeDecimal * 10;
    
    lcd.setCursor(0,1);
    lcd.print(beforeDecimal);
    lcd.print(".");
    lcd.print(afterDecimal);
    lcd.print(" (");
    lcd.write((byte)0);
    lcd.print("C)");
    
    btnInput = analogRead(0);
    
    delay(50);
  }
  lcd.clear();
  
  pinMode(blinkPin,OUTPUT);         // pin that will blink to your heartbeat!
  pinMode(fadePin,OUTPUT);          // pin that will fade to your heartbeat!
  Serial.begin(115200);             // we agree to talk fast!
  interruptSetup();                 // sets up to read Pulse Sensor signal every 2mS 
   // IF YOU ARE POWERING The Pulse Sensor AT VOLTAGE LESS THAN THE BOARD VOLTAGE, 
   // UN-COMMENT THE NEXT LINE AND APPLY THAT VOLTAGE TO THE A-REF PIN
//   analogReference(EXTERNAL);

  
}


//  Where the Magic Happens
void loop(){
  
    serialOutput() ;       
    
  if (QS == true){     // A Heartbeat Was Found
                       // BPM and IBI have been Determined
                       // Quantified Self "QS" true when arduino finds a heartbeat
        fadeRate = 255;         // Makes the LED Fade Effect Happen
                                // Set 'fadeRate' Variable to 255 to fade LED with pulse
        serialOutputWhenBeatHappens();   // A Beat Happened, Output that to serial.     
        QS = false;                      // reset the Quantified Self flag for next time    
  }
     
  ledFadeToBeat();                      // Makes the LED Fade Effect Happen 
  delay(20);                             //  take a break
}





void ledFadeToBeat(){
    fadeRate -= 15;                         //  set LED fade value
    fadeRate = constrain(fadeRate,0,255);   //  keep LED fade value from going into negative numbers!
    analogWrite(fadePin,fadeRate);          //  fade LED
  }




