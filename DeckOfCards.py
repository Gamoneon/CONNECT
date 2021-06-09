#sorting deck
import random
decks=['01S','02S','03S','04S','05S','06S','07S','08S','09S','10S','11S','12S','13S','01D','02D','03D','04D','05D','06D','07D','08D','09D','10D','11D','12D','13D','01C','02C','03C','04C','05C','06C','07C','08C','09C','10C','11C','12C','13C','01H','02H','03H','04H','05H','06H','07H','08H','09H','10H','11H','12H','13H']
random.shuffle(decks)
print("random deck is ",decks)

spade,diamond,club,heart=[],[],[],[]

def decksort(list,d):
    list.sort()
    list[0]='ACE '+d
    list[10]='JOKER '+d
    list[11]='QUEEN '+d
    list[12]='KING '+d

for i in decks:
        d = i[2]
        if d == 'S':
            spade.append(i)
        elif d == 'D':
            diamond.append(i)
        elif d == 'H':
            heart.append(i)
        elif d == 'C':
            club.append(i)

decksort(spade,'S')
decksort(diamond,'D')
decksort(heart,'H')
decksort(club,'C')

print(f"\nSpade:{spade} \nDiamond:{diamond}\nClub:{club}\nHeart:{heart}")
