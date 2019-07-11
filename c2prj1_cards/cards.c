#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"


void assert_card_valid(card_t c) {
  assert((c.value >= 2) && (c.value <= VALUE_ACE));
  assert((c.suit >= SPADES) && (c.suit <= CLUBS));
}

const char * ranking_to_string(hand_ranking_t r) {
  switch(r){
  case STRAIGHT_FLUSH: return "STRAIGHT_FLUSH";
  case FOUR_OF_A_KIND: return "FOUR_OF_A_KIND";
  case FULL_HOUSE: return "FULL_HOUSE";
  case FLUSH: return "FLUSH";
  case STRAIGHT: return "STRAIGHT";
  case THREE_OF_A_KIND: return "THREE_OF_A_KIND";
  case TWO_PAIR: return "TWO_PAIR";
  case PAIR: return "PAIR";
  default: return "NOTHING";
  }
}


char value_letter(card_t c) {
  char z;

  if ((c.value < 2) || (c.value > VALUE_ACE)){
    printf("Invalid value. Please enter a valid card value !\n");
    return 0;
  }

  if ((c.value >= 2) && (c.value <= 9)){
    z = '0' + c.value;
    return z;
  }
  
  else if (c.value == 10){
    z = '0';
    }
  else if (c.value == VALUE_JACK){
    z = 'J';
    }
  else if (c.value == VALUE_QUEEN){
    z = 'Q';
    }
  else if (c.value == VALUE_KING){
    z = 'K';
    }
  else if (c.value == VALUE_ACE){
    z = 'A';
    }
    return z;
}


char suit_letter(card_t c) {

  if ((c.suit < SPADES) || (c.suit > CLUBS)){
    printf("No such card exists. Please type SPADES / HEARTS / DIAMOND / CLUBS !\n");
    return 0;
  }
  
  switch(c.suit){
  case SPADES: return 's';
  case HEARTS: return 'h';
  case DIAMONDS: return 'd';
  case CLUBS: return 'c';
  default: return 'X';
      }
}


void print_card(card_t c) {
  char value, suit;

  value = value_letter(c);
  suit = suit_letter(c);

  printf("%c%c", value, suit);
}


card_t card_from_letters(char value_let, char suit_let) {
  card_t temp;

  assert((value_let == 48) || ((value_let >= 50) && (value_let <= 57)) || (value_let == 65) || (value_let == 74) || (value_let == 75) || (value_let == 81));

  assert((suit_let == 115) || (suit_let == 104) || (suit_let == 100) || (suit_let == 99));
  
  // temp.value **
  switch(value_let){
  case '2': temp.value = 2; break;
  case '3': temp.value = 3; break;
  case '4': temp.value = 4; break;
  case '5': temp.value = 5; break;
  case '6': temp.value = 6; break;
  case '7': temp.value = 7; break;
  case '8': temp.value = 8; break;
  case '9': temp.value = 9; break;
  case '0': temp.value = 10; break;
  case 'J': temp.value = VALUE_JACK; break;
  case 'Q': temp.value = VALUE_QUEEN; break;
  case 'K': temp.value = VALUE_KING; break;
  case 'A': temp.value = VALUE_ACE; break;
  }
     
  // temp.suit **
  switch(suit_let){
  case 's': temp.suit = SPADES; break;
  case 'h': temp.suit = HEARTS; break;
  case 'd': temp.suit = DIAMONDS; break;
  case 'c': temp.suit = CLUBS; break;
  }

  return temp;
}


card_t card_from_num(unsigned c) {
  card_t temp;

  if ((c < 0) || (c > 51)){
    printf("Card number not in valid range 0 - 51\n");
  }

  if (c >= 0 && c <= 12)
    {
      temp.suit = SPADES;
      switch(c){
      case 0: temp.value = 2; break;
      case 1: temp.value = 3; break;
      case 2: temp.value = 4; break;
      case 3: temp.value = 5; break;
      case 4: temp.value = 6; break;
      case 5: temp.value = 7; break;
      case 6: temp.value = 8; break;
      case 7: temp.value = 9; break;
      case 8: temp.value = 10; break;
      case 9: temp.value = VALUE_JACK; break;
      case 10: temp.value = VALUE_QUEEN; break;
      case 11: temp.value = VALUE_KING; break;
      case 12: temp.value = VALUE_ACE; break;
    }
    }
  else if (c >= 13 && c <= 25)
    {
    temp.suit = HEARTS;
    switch(c){
      case 13: temp.value = 2; break;
      case 14: temp.value = 3; break;
      case 15: temp.value = 4; break;
      case 16: temp.value = 5; break;
      case 17: temp.value = 6; break;
      case 18: temp.value = 7; break;
      case 19: temp.value = 8; break;
      case 20: temp.value = 9; break;
      case 21: temp.value = 10; break;
      case 22: temp.value = VALUE_JACK; break;
      case 23: temp.value = VALUE_QUEEN; break;
      case 24: temp.value = VALUE_KING; break;
      case 25: temp.value = VALUE_ACE; break;
    }
    }
  else if (c >= 26 && c <= 38)
    {
      temp.suit = DIAMONDS;
      switch(c){
      case 26: temp.value = 2; break;
      case 27: temp.value = 3; break;
      case 28: temp.value = 4; break;
      case 29: temp.value = 5; break;
      case 30: temp.value = 6; break;
      case 31: temp.value = 7; break;
      case 32: temp.value = 8; break;
      case 33: temp.value = 9; break;
      case 34: temp.value = 10; break;
      case 35: temp.value = VALUE_JACK; break;
      case 36: temp.value = VALUE_QUEEN; break;
      case 37: temp.value = VALUE_KING; break;
      case 38: temp.value = VALUE_ACE; break;
    }
    }
  else if (c >= 39 && c <= 51)
    {
      temp.suit = CLUBS;
      switch(c){
      case 39: temp.value = 2; break;
      case 40: temp.value = 3; break;
      case 41: temp.value = 4; break;
      case 42: temp.value = 5; break;
      case 43: temp.value = 6; break;
      case 44: temp.value = 7; break;
      case 45: temp.value = 8; break;
      case 46: temp.value = 9; break;
      case 47: temp.value = 10; break;
      case 48: temp.value = VALUE_JACK; break;
      case 49: temp.value = VALUE_QUEEN; break;
      case 50: temp.value = VALUE_KING; break;
      case 51: temp.value = VALUE_ACE; break;
    }
    }

  return temp;
}
