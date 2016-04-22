#define DATA_DECL int a1, a2, a3, a4, a5
#define DATA_INIT a1 = 0; a2 = 0; a3 = 0; a4 = 0; a5 = 0;

class Empty{ };

class EmptyC{
public:
	EmptyC(){ }
};

class EmptyD{
public:
	~EmptyD(){ }
};

class EmptyCD
{
public:
	EmptyCD(){ }

	~EmptyCD(){ }	
};



class Filled
{
public:
	DATA_DECL;
};

class FilledC
{
public:
	FilledC(){
		DATA_INIT;
	}

	DATA_DECL;	
};

class FilledD
{
public:
	~FilledD(){ }
	
	DATA_DECL;
};

class FilledCD
{
public:
	FilledCD(){
		DATA_INIT;
	}

	~FilledCD(){ }
	
	DATA_DECL;
};