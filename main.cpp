#include <iostream>

int** fn_GenBomb(int* ip_BI);
void fn_Remv2DDyArr(int** i2p_Arr, int i_Row= 10);
void fn_ShowMap(int** i2p_Arr, int i_Row= 10, int i_Col= 10);

int main(){
    int** i2p_Bomb      = nullptr;
    int* ip_BI          = new int[10]{0, 7, 13, 28, 44, 62, 74, 75, 87, 90};
    i2p_Bomb            = fn_GenBomb(ip_BI);
    fn_ShowMap(i2p_Bomb);


    fn_Remv2DDyArr(i2p_Bomb);
    delete [] ip_BI;
    return 0;
}

int** fn_GenBomb(int* ip_BI){
    int** i2p_Bomb              = new int*[10];
    for(int i_Ct=0; i_Ct< 10; i_Ct++){
        i2p_Bomb[i_Ct]          = new int[10]{};
    }

    for(int i_Ct= 0; i_Ct< 10; i_Ct++){
        int i_Row = ip_BI[i_Ct]/ 10;
        int i_Col = ip_BI[i_Ct]% 10;
        i2p_Bomb[i_Row][i_Col]  = -1;
    }

    for(int i_Ct= 0; i_Ct< 10; i_Ct++){
        for(int i_Ct2=1; i_Ct2<=9; i_Ct2++){
            int i_Ind           = ip_BI[i_Ct];
            int i_Tmp       =  i_Ind / 10;
            int i_Tmp2      =  -1;
            switch(i_Ct2){
                case 1:
                    i_Ind       -= 11;
                    i_Tmp2      = i_Ind / 10;
                    i_Ind       = ((i_Tmp - 1) != i_Tmp2)? -1: i_Ind;
                    break;
                case 2:
                    i_Ind       -= 10;
                    break;
                case 3:
                    i_Ind       -= 9;
                    i_Tmp2      = i_Ind / 10;
                    i_Ind       = (i_Tmp == i_Tmp2)? -1: i_Ind;
                    break;
                case 4:
                    i_Ind       -= 1;
                    i_Tmp2      = i_Ind / 10;
                    i_Ind       = (i_Tmp != i_Tmp2)? -1: i_Ind;
                    break;
                case 5:
                    break;
                case 6:
                    i_Ind       += 1;
                    i_Tmp2      = i_Ind / 10;
                    i_Ind       = (i_Tmp != i_Tmp2)? -1: i_Ind;
                    break;
                case 7:
                    i_Ind       += 9;
                    i_Tmp2      = i_Ind / 10;
                    i_Ind       = (i_Tmp == i_Tmp2)? -1: i_Ind;
                    break;
                case 8:
                    i_Ind       += 10;
                    break;
                case 9:
                    i_Ind       += 11;
                    i_Tmp2      = i_Ind / 10;
                    i_Ind       = ((i_Tmp + 1) != i_Tmp2)? -1: i_Ind;
                    break;
                default:
                    exit(1);
                    break;
            }
            i_Ind       = (i_Ind < 0 || i_Ind >=100)? -1: i_Ind;
            if(i_Ind != -1){
                int i_Row = i_Ind/ 10;
                int i_Col = i_Ind% 10;
                if(i2p_Bomb[i_Row][i_Col] != -1){
                    i2p_Bomb[i_Row][i_Col]++;
                }
            }
        }
    }

    return i2p_Bomb;
}


void fn_Remv2DDyArr(int** i2p_Arr, int i_Row){
    for(int i_Ct=0; i_Ct< i_Row; i_Ct++){
        delete [] i2p_Arr[i_Ct];
    }
}

void fn_ShowMap(int** i2p_Arr, int i_Row, int i_Col){
    for(int i_Ct=0; i_Ct< i_Row; i_Ct++){
        for(int i_Ct2=0; i_Ct2< i_Col; i_Ct2++){
            if(i2p_Arr[i_Ct][i_Ct2]== -1){
                std:: cout<< "*";
            }
            else if(i2p_Arr[i_Ct][i_Ct2] == 0){
                std:: cout<< " ";
            }
            else{
                std:: cout<< i2p_Arr[i_Ct][i_Ct2];
            }
        }
        std::cout<< "\n";
    }
}
