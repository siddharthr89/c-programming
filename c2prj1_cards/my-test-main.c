#include "cards.h"

int main(void) {

  card_t a;

  a.value = 13;
  a.suit = 1;
  
  assert_card_valid(a);
  card_from_letters('2','h');
}
