
#include <stdio.h>

char determineBanquetRoom(int guests);
float determineRoomPrice(char room);
float determineFoodPrice(int guests);
float determineEquipmentPrice();
void displayPrices(char room,int guests,float prices[]);

int main()
{
  char room, equipment;
  int guests, numberOfTables;
  float prices[4] = {0};		// roomPrice -- tablePrice  -- foodPrice --- equipmentPrice

  printf("Welcome to Holiday Banquet Center!");
  printf("\nHow many guests do you expect:  ");
  scanf("%d", &guests);
  while (guests < 15 || guests > 250)
  {
    printf("\nYou have entered an invalid number of guests.");
    printf("\nHow many guests do you expect:  ");
    scanf("%d", &guests);
  }

  room = determineBanquetRoom(guests);

  prices[0] = determineRoomPrice(room);

  numberOfTables = guests / 10;
  numberOfTables += 2;
  prices[1] = numberOfTables * 15.00;

  prices[2] = determineFoodPrice(guests);

  printf("\nDo you need additional equipment Y/N? :   ");
  scanf("\n%c", &equipment);

  if (equipment == 'Y' || equipment == 'y')
    prices[3] = determineEquipmentPrice();

  displayPrices(room, guests, prices);

  return 0;
}
void displayPrices(char room,int guests,float prices[])
{
  float finalTotal=0, serviceFee=0;

  printf("\n\nYour quote to rent the ");
  switch (room)
  {
    case 'C': case 'c':
      printf("Cozy Cabin");
      break;
    case 'P': case 'p':
      printf("Purple Parlor Room");
      break;
    case 'D': case 'd':
      printf("Deluxe Dining Room");
      break;
    case 'B': case 'b':
      printf("Big Ballroom");
      break;
    case 'G': case 'g':
      printf("Grand Guestroom");
      break;
  }
  printf(" for %d guests will be:  \n", guests);
  printf("\nRoom Price:                   $%8.2f", prices[0]);
  printf("\nTable Price:                  $%8.2f", prices[1]);
  printf("\nFood Price:                   $%8.2f", prices[2]);
  printf("\nEquipment Price:              $%8.2f", prices[3]);

  for (int x = 0 ; x < 4 ; x++)
    finalTotal += prices[x];

  serviceFee = .21 * finalTotal;

  printf("\nService Fee:                   $%8.2f", serviceFee);

  finalTotal += serviceFee;
  printf("\n\nFinal Price:                   $%8.2f", finalTotal);

}



float determineEquipmentPrice()
{
  float equipmentPrice = 0;
  float prices[5] = {100.00, 25.00, 50.00, 10.00, 5.00 };
  int choice;

    printf("\n1 - Projector       $%8.2f", prices[0]);
    printf("\n2 - Screen          $%8.2f", prices[1]);
    printf("\n3 - Sound Box       $%8.2f", prices[2]);
    printf("\n4 - 8-foot Table    $%8.2f", prices[3]);
    printf("\n5 - Easel           $%8.2f", prices[4]);
    printf("\n\nEnter a choice or 0 to quit:  ");
    scanf("%d", &choice);

  while (choice != 0)
  {
    equipmentPrice += prices[choice-1];
    printf("\nYour equipment cost is currently:  $%.2f\n", equipmentPrice);
    printf("\n1 - Projector       $%8.2f", prices[0]);
    printf("\n2 - Screen          $%8.2f", prices[1]);
    printf("\n3 - Sound Box       $%8.2f", prices[2]);
    printf("\n4 - 8-foot Table    $%8.2f", prices[3]);
    printf("\n5 - Easel           $%8.2f", prices[4]);
    printf("\n\nEnter a choice or 0 to quit:  ");
    scanf("%d", &choice);

  }

  return equipmentPrice;
}


float determineFoodPrice(int guests)
{
  int numEntrees;
  float pricePerPerson, foodPrice = 0;
  char dessert;

  printf("\nWould you like one main entree or two? ");
  scanf("%d", &numEntrees);
  while (numEntrees < 1 || numEntrees > 2)
  {
    printf("\nInvalid!  Try again!  ");
    printf("\nWould you like 1 main entree or 2? ");
    scanf("%d", &numEntrees);
  }

  pricePerPerson = 17.00;

  if (numEntrees == 2)
    pricePerPerson = 19.50;

  printf("\nWould you like dessert Y/N? ");
  scanf("\n%c", &dessert);

  if (dessert == 'Y' || dessert == 'y')
    pricePerPerson += 2.00;

  return guests * pricePerPerson;
}

float determineRoomPrice(char room)
{
  float roomPrice;

  switch (room)
  {
    case 'C': case 'c':
    case 'P': case 'p':
      roomPrice = 250.00;
      break;
    case 'D': case 'd':
    case 'B': case 'b':
      roomPrice = 500.00;
      break;
    case 'G': case 'g':
      roomPrice = 750.00;
      break;
  }

  return roomPrice;
}

char determineBanquetRoom(int guests)
{
  char room;

  printf("\nBased on the number of guests, you have the choice of the following rooms: ");

  if (guests <= 25)
    printf("\nC - Cozy Cabin");
  if (guests <= 75)
    printf("\nP - Purple Parlor");
  if (guests >= 50 && guests <= 125)
    printf("\nD - Deluxe Dining");
  if (guests >= 50 && guests <= 150)
    printf("\nB - Big Ballroom");
  if (guests >= 100 && guests <= 250)
    printf("\nG - Grand Guestroom");

  printf("\nPlease choose from the available rooms above: --> ");
  scanf("\n%c", &room);

  return room;
}





