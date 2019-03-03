

float mdl(float a)
{
	if (a < 0)
	{
		return (-1 * a);
	}
	return a;
}

int mdl(int a)
{
	if (a < 0)
	{
		return (-1 * a);
	}
	return a;
}

double mdl(double a)
{
	if (a < 0)
	{
		return (-1 * a);
	}
	return a;
}

double pw(double _X, int _Y)
{
        unsigned int _N;
        if (_Y >= 0)
                _N = (unsigned int)_Y;
        else
                _N = (unsigned int)(-_Y);
        for (double _Z = double(1); ; _X *= _X)
        {
                if ((_N & 1) != 0)
                        _Z *= _X;
                if ((_N >>= 1) == 0)
                        return (_Y < 0 ? double(1) / _Z : _Z); 
        }
}
