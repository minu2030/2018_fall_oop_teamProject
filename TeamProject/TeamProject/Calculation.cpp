#include "Calculation.h"


int Calculation::calculate_Cost(int length) {	//총 비용 계산 함수( 1km당 900원으로 계산)
	return 900 * length;
}

double Calculation::alloc_Cost(int total, int length) {	//내야할 돈의 비율을 계산해준다.
	return (double)length / total;
}

int Calculation::calculate_Personal_Cost(int total, double percent) {	//개인별 내야할 돈을 계산해준다.
	double returnValue = total * percent;	//총액 x 비율로 돈계산
	returnValue = floor(returnValue+0.5);	//반올림해서 저장한다.
	return (int)returnValue;	//어차피 반올림으로인해 정수가 되었으니 형변환해서 반환한다.
}

