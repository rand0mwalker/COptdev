#include "Core"


typedef COPT::KernelTrait<double> 			kernel;
typedef kernel::Matrix 						Matrix;

int main(int argc, char *argv[])
{
	Matrix mat = Matrix::identity(5,5);
	mat(0,4)=1.0;
	mat(0,3)=1.0;
	Matrix mtm;
	mat.mtm(mtm);
	// mat.setSymmetricFlag(true);
	COPT::EigenSolver<Matrix> ev(mtm);
	std::cout<<ev.eigenValue()<<std::endl;
	std::cout<<ev.eigenVector()*Matrix::diag(5,5,ev.eigenValue())*ev.eigenVector().transpose()<<std::endl;
}