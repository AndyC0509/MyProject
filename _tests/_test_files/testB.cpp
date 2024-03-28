#include "gtest/gtest.h"
#include <cmath>
#include <iostream>
#include <iomanip>
#include <set>
#include <vector>
#include <fstream>

using namespace std;
//------------------------------------------------------------------------------------------
//Files we are testing:

#include "../../includes/tokenizer/ftokenize.h"
//#include "solitude_mini.txt"


//------------------------------------------------------------------------------------------

using namespace std;
void test_f_tokenize_simple();


bool test_tokenize(bool debug = false)
{
  test_f_tokenize_simple();
  return true;
}


  void test_f_tokenize_simple()
  {
    //****************************
    //========================== *
    //= set MAX_BUFFER to 200  = *
    //=    For this run        = *
    //========================== *
    //****************************

    
    // Token t;
    // FTokenizer ftk("solitude_mini.txt");
    //ofstream MyFile("solitude-mini.txt");
    //MyFile << "abcdefguuu";
    //MyFile.close();

    //ifstream f;
    //char s[50];
    //FTokenizer ftk("solitude_mini.txt");
    // f.open("solitude-mini.txt");
    // if(f.fail())
    // {
    //   cout << "Not open: "<<endl;
    // }
    //f.read(s,15);
    //f.close();
    //cout << s << endl;
    //int j = 0;
    //cout << f.gcount() <<endl;
    // while(f.gcount() > 0)
    // {
    //   s[f.gcount()] = j;
      
    //cout << s << " " << f.gcount() <<endl;
    //   f.read(s, 15);
    // }
    
    
    // while(!infile.eof())
    // {
    //   infile >> words;
    //   cout<<words<<endl;
    // }



    

  
   
    
    // char* buffer;
    // ifstream.read(buffer);
    //ftk>>t;
    
//     int token_count = 0;

//     while (ftk.more())
//     {
//         if (t.type_string()=="ALPHA" ){
//             token_count++;
// //            if (token_count == 100) break;
//             cout<<setw(10)<<right<<token_count<<setw(3)<<left<<":"
//                <<setw(25)<<left<<t.token_str()<<t.type_string()<<setw(20)<<right<<strlen(t.token_str().c_str())<<endl;
//         }
//         //ftk>>t;
//     }
//     cout<<"Tokens Found: "<<token_count<<endl;
//     cout<<"=========="<<endl;

}



TEST(TEST_TOKENIZER, TestTokenize) {
  bool success = test_tokenize(true);
  EXPECT_EQ(success, true);
}



int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  std::cout<<"\n\n----------running testB.cpp---------\n\n"<<std::endl;
  return RUN_ALL_TESTS();
}

/*

-------------------- build/solitude_mini.txt --------------------------------


Chapter 1
MANY YEARS LATER as he faced the firing squad, Colonel Aureliano Buendía was to remember that distant afternoon when his father took him to discover ice. At that time Macondo was a village of twenty adobe houses, built on the bank of a river of clear water that ran along a bed of polished stones, which were white and enormous, like prehistoric eggs. 

The world was so recent that many things lacked names, and in order to indicate them it was necessary to point. Every year during the month of March a family of ragged gypsies would set up their tents near the village, and with a great uproar of pipes and kettledrums they would display new inventions. First they brought the magnet. A heavy gypsy with an untamed beard and sparrow hands, who introduced himself as Melquíades, put on a bold public demonstration of what he himself called the eighth wonder of the learned alchemists of Macedonia.




------------------------------------------------------------------------

tokenizer git:(master) ✗  😊 $> tree includes
includes
└── tokenizer
    ├── constants.h
    ├── ftokenize.cpp
    ├── ftokenize.h
    ├── state_machine_functions.cpp
    ├── state_machine_functions.h
    ├── stokenize.cpp
    ├── stokenize.h
    ├── token.cpp
    └── token.h

1 directory, 9 files
tokenizer git:(master) ✗  😊 $> cd build
build git:(master) ✗  😊 $> ./bin/basic_test


----------running basic_test.cpp---------


[==========] Running 1 test from 1 test case.
[----------] Global test environment set-up.
[----------] 1 test from TEST_TOKENIZER
[ RUN      ] TEST_TOKENIZER.TestTokenize

----- New Block ---------------------[199] bytes
         1:  Chapter                  ALPHA                   7
         2:  MANY                     ALPHA                   4
         3:  YEARS                    ALPHA                   5
         4:  LATER                    ALPHA                   5
         5:  as                       ALPHA                   2
         6:  he                       ALPHA                   2
         7:  faced                    ALPHA                   5
         8:  the                      ALPHA                   3
         9:  firing                   ALPHA                   6
        10:  squad                    ALPHA                   5
        11:  Colonel                  ALPHA                   7
        12:  Aureliano                ALPHA                   9
        13:  Buend                    ALPHA                   5
        14:  a                        ALPHA                   1
        15:  was                      ALPHA                   3
        16:  to                       ALPHA                   2
        17:  remember                 ALPHA                   8
        18:  that                     ALPHA                   4
        19:  distant                  ALPHA                   7
        20:  afternoon                ALPHA                   9
        21:  when                     ALPHA                   4
        22:  his                      ALPHA                   3
        23:  father                   ALPHA                   6
        24:  took                     ALPHA                   4
        25:  him                      ALPHA                   3
        26:  to                       ALPHA                   2
        27:  discover                 ALPHA                   8
        28:  ice                      ALPHA                   3
        29:  At                       ALPHA                   2
        30:  that                     ALPHA                   4
        31:  time                     ALPHA                   4
        32:  Macondo                  ALPHA                   7
        33:  was                      ALPHA                   3
        34:  a                        ALPHA                   1
        35:  village                  ALPHA                   7

----- New Block ---------------------[199] bytes
        36:  of                       ALPHA                   2
        37:  twenty                   ALPHA                   6
        38:  adobe                    ALPHA                   5
        39:  houses                   ALPHA                   6
        40:  built                    ALPHA                   5
        41:  on                       ALPHA                   2
        42:  the                      ALPHA                   3
        43:  bank                     ALPHA                   4
        44:  of                       ALPHA                   2
        45:  a                        ALPHA                   1
        46:  river                    ALPHA                   5
        47:  of                       ALPHA                   2
        48:  clear                    ALPHA                   5
        49:  water                    ALPHA                   5
        50:  that                     ALPHA                   4
        51:  ran                      ALPHA                   3
        52:  along                    ALPHA                   5
        53:  a                        ALPHA                   1
        54:  bed                      ALPHA                   3
        55:  of                       ALPHA                   2
        56:  polished                 ALPHA                   8
        57:  stones                   ALPHA                   6
        58:  which                    ALPHA                   5
        59:  were                     ALPHA                   4
        60:  white                    ALPHA                   5
        61:  and                      ALPHA                   3
        62:  enormous                 ALPHA                   8
        63:  like                     ALPHA                   4
        64:  prehistoric              ALPHA                  11
        65:  eggs                     ALPHA                   4
        66:  The                      ALPHA                   3
        67:  world                    ALPHA                   5
        68:  was                      ALPHA                   3
        69:  so                       ALPHA                   2
        70:  recent                   ALPHA                   6
        71:  that                     ALPHA                   4
        72:  many                     ALPHA                   4

----- New Block ---------------------[199] bytes
        73:  things                   ALPHA                   6
        74:  lacked                   ALPHA                   6
        75:  names                    ALPHA                   5
        76:  and                      ALPHA                   3
        77:  in                       ALPHA                   2
        78:  order                    ALPHA                   5
        79:  to                       ALPHA                   2
        80:  indicate                 ALPHA                   8
        81:  them                     ALPHA                   4
        82:  it                       ALPHA                   2
        83:  was                      ALPHA                   3
        84:  necessary                ALPHA                   9
        85:  to                       ALPHA                   2
        86:  point                    ALPHA                   5
        87:  Every                    ALPHA                   5
        88:  year                     ALPHA                   4
        89:  during                   ALPHA                   6
        90:  the                      ALPHA                   3
        91:  month                    ALPHA                   5
        92:  of                       ALPHA                   2
        93:  March                    ALPHA                   5
        94:  a                        ALPHA                   1
        95:  family                   ALPHA                   6
        96:  of                       ALPHA                   2
        97:  ragged                   ALPHA                   6
        98:  gypsies                  ALPHA                   7
        99:  would                    ALPHA                   5
       100:  set                      ALPHA                   3
       101:  up                       ALPHA                   2
       102:  their                    ALPHA                   5
       103:  tents                    ALPHA                   5
       104:  near                     ALPHA                   4
       105:  the                      ALPHA                   3
       106:  village                  ALPHA                   7
       107:  and                      ALPHA                   3
       108:  with                     ALPHA                   4
       109:  a                        ALPHA                   1
       110:  gr                       ALPHA                   2

----- New Block ---------------------[199] bytes
       111:  eat                      ALPHA                   3
       112:  uproar                   ALPHA                   6
       113:  of                       ALPHA                   2
       114:  pipes                    ALPHA                   5
       115:  and                      ALPHA                   3
       116:  kettledrums              ALPHA                  11
       117:  they                     ALPHA                   4
       118:  would                    ALPHA                   5
       119:  display                  ALPHA                   7
       120:  new                      ALPHA                   3
       121:  inventions               ALPHA                  10
       122:  First                    ALPHA                   5
       123:  they                     ALPHA                   4
       124:  brought                  ALPHA                   7
       125:  the                      ALPHA                   3
       126:  magnet                   ALPHA                   6
       127:  A                        ALPHA                   1
       128:  heavy                    ALPHA                   5
       129:  gypsy                    ALPHA                   5
       130:  with                     ALPHA                   4
       131:  an                       ALPHA                   2
       132:  untamed                  ALPHA                   7
       133:  beard                    ALPHA                   5
       134:  and                      ALPHA                   3
       135:  sparrow                  ALPHA                   7
       136:  hands                    ALPHA                   5
       137:  who                      ALPHA                   3
       138:  introduced               ALPHA                  10
       139:  himself                  ALPHA                   7
       140:  as                       ALPHA                   2
       141:  Melqu                    ALPHA                   5
       142:  ades                     ALPHA                   4
       143:  put                      ALPHA                   3

----- New Block ---------------------[116] bytes
       144:  on                       ALPHA                   2
       145:  a                        ALPHA                   1
       146:  bold                     ALPHA                   4
       147:  public                   ALPHA                   6
       148:  demonstration            ALPHA                  13
       149:  of                       ALPHA                   2
       150:  what                     ALPHA                   4
       151:  he                       ALPHA                   2
       152:  himself                  ALPHA                   7
       153:  called                   ALPHA                   6
       154:  the                      ALPHA                   3
       155:  eighth                   ALPHA                   6
       156:  wonder                   ALPHA                   6
       157:  of                       ALPHA                   2
       158:  the                      ALPHA                   3
       159:  learned                  ALPHA                   7
       160:  alchemists               ALPHA                  10
       161:  of                       ALPHA                   2
       162:  Macedonia                ALPHA                   9
*** END OF FILE ***
Tokens Found: 162
==========
[       OK ] TEST_TOKENIZER.TestTokenize (26 ms)
[----------] 1 test from TEST_TOKENIZER (26 ms total)

[----------] Global test environment tear-down
[==========] 1 test from 1 test case ran. (27 ms total)
[  PASSED  ] 1 test.
build git:(master) ✗  😊 $>      



*/

