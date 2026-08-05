#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr<<"Error: wrong number of arguments"<<std::endl;
		return 1;
	}
	try
	{
		RPN obj;
		obj.parseArgument(std::string(argv[1]));
	}
	catch (std::exception &e) {
		std::cerr<<e.what()<<std::endl;
	}
	return 0;
}
// önce string şekilde girdiğimiz girdiyi tek tek parse etsin
// sonra her elemanı alsın, sayıysa integera çevirsin; değilse operatörlerimizden biri mi diye kontrol etsin
// parse işlemini tek tek yapıp containera atsın
// postfix-prefix işlemlerinde genellikle stack tanımlanıyor. Salim hoca öyle yapıyordu, data structure
// sonra döngü içerisinde ilk operatör gördüğü yerde [indx - 2] [op] [indx - 1] işlemini yapsın (bunu vectorle yapabilirmişim
// ilk başta vectore göre düşünüp planlamıştım o yüzden bu iptal)
// top() - pop() - push() yapıcaazzz
// ve bu sonucu bir değerde saklasın (result). en son result değerini döndürsün

//hata verilecek durumlar:
// eksik argüman -> çıkış (Error: wrong number of arguments)
// yanlış operatör -> çıkış (Error)
// verilen sayılar 10 dan küçük olmalı, büyükse -> çıkış (Error)
// Error diye bir exception tanımla en iyisi
// division by zero "5 0 /"" -> Error
// NULL girdi ya da sadece sayı "", "5" -> Error
// tek eleman "1 +" -> Error

// all errors will display in stdandart error