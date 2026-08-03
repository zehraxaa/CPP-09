#include "RPN.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	(void)argv;
	if (argc != 2)
	{
		std::cerr<<"Error: wrong number of arguments"<<std::endl;
		return 1;
	}
}
// önce string şekilde girdiğimiz girdiği tek tek parse etsin
// sonra her elemanı alsın, sayıysa integera çevirsin; değilse operatörlerimizden biri mi diye kontrol etsin
// parse işlemini tek tek yapıp containera atsın
// sonra döngü içerisinde ilk operatör gördüğü yerde [indx - 2] [op] [indx - 1] işlemini yapsın
// ve bu sonucu bir değerde saklasın (result). en son result değerini döndürsün

//hata verilecek durumlar:
// eksik argüman -> çıkış (Error: wrong number of arguments)
// yanlış operatör -> çıkış (Error)
// verilen sayılar 10 dan küçük olmalı, büyükse -> çıkış (Error)
// Error diye bir exception tanımla en iyisi

// all errors will display in stdandart error