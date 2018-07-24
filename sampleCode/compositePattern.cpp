//Composite Design Pattern

class CComponent
{
public:
	virtual bool AddCEntity(CComponent* pEntity)
	{
		std::cout << "CComponent::AddCEntity called" << std::endl;
		bool bRet = false;
		return(bRet);
	};
	virtual size_t NumOfCEntities()
	{
		std::cout << "CComponent::NumOfCEntities called" << std::endl;
		return(0);
	};
	virtual bool RemoveCEntity(const CComponent *pEntity)
	{
		std::cout << "CComponent::RemoveCEntity called" << std::endl;
		bool bRet = false;
		return(bRet);
	};
	CComponent()
	{
		std::cout << "CComponent::CComponent called" << std::endl;
	};
	virtual ~CComponent()
	{
		std::cout << "CComponent::~CComponent called" << std::endl;
	};
	std::string GetName() const{return(_name);};
	virtual void Dump()
	{
		std::cout << "Name of the component is: " << _name << std::endl;
	};
protected:
	std::string _name;
private:
};

class CFile : public CComponent
{
public:
	CFile(const std::string name)
	{
		std::cout << "CFile::CFile called" << std::endl;
		_name = name;
	};
	virtual ~CFile()
	{
		std::cout << "CFile::~CFile called" << std::endl;
	};
protected:
private:
};

class CDirectory : public CComponent
{
public:
	CDirectory(const std::string name)
	{
		std::cout << "CDirectory::CDirectory called" << std::endl;
		_name = name;
		_pListOfEntities.clear();
	};
	virtual ~CDirectory()
	{
		std::cout << "CDirectory::~CDirectory called" << std::endl;
		_pListOfEntities.clear();
	};
	bool AddCEntity(CComponent *pEntity)
	{
		bool bRet = false;
		std::cout << "CDirectory::AddCEntity called" << std::endl;
		if (NULL != pEntity)
		{
			_pListOfEntities.push_back(pEntity);
			bRet = true;
		}

		return(bRet);
	};
	bool RemoveCEntity(const CComponent *pEntity)
	{
		bool bRet = false;
		std::cout << "CDirectory::RemoveCEntity called" << std::endl;
		if (NULL != pEntity)
		{
			std::vector<CComponent*>::iterator endIter = _pListOfEntities.end();
			std::vector<CComponent*>::iterator iter = std::find(_pListOfEntities.begin(),
				_pListOfEntities.end(), pEntity);
			if (iter != endIter)
			{
				_pListOfEntities.erase(iter);
				bRet = true;
			}
		}
		return(bRet);
	};
	size_t NumOfCEntities()
	{
		std::cout << "CDirectory::NumOfCEntities called" << std::endl;
		return(_pListOfEntities.size());
	};
	void Dump()
	{
		std::cout << "Name of the component is: " << _name << std::endl;
		std::vector<CComponent*>::iterator iter = _pListOfEntities.begin();
		std::vector<CComponent*>::iterator endIter = _pListOfEntities.end();
		for (; iter != endIter; ++iter)
		{
			(*iter)->Dump();
		}
	};
protected:
private:
	std::vector<CComponent*> _pListOfEntities;
};

//int main()
//{
//	CComponent *pFile_01 = new CFile("file01.fl");
//	CComponent *pFile_02 = new CFile("file02.fl");
//	CComponent *pFile_03 = new CFile("file03.fl");
//	CComponent *pFile_04 = new CFile("file04.fl");
//
//	CComponent *pDirectory_01 = new CDirectory("directory_01");
//	CComponent *pDirectory_02 = new CDirectory("directory_02");
//	CComponent *pDirectory_03 = new CDirectory("directory_03");
//	CComponent *pDirectory_04 = new CDirectory("directory_04");
//
//	bool bRet = pDirectory_01->AddCEntity(pFile_01);
//	assert(true == bRet);
//	bRet = pDirectory_01->AddCEntity(pFile_02);
//	assert(true == bRet);
//
//	bRet = pDirectory_02->AddCEntity(pFile_03);
//	assert(true == bRet);
//
//	bRet = pDirectory_04->AddCEntity(pDirectory_01);
//	assert(true == bRet);
//	bRet = pDirectory_04->AddCEntity(pDirectory_02);
//	assert(true == bRet);
//	bRet = pDirectory_04->AddCEntity(pDirectory_03);
//	assert(true == bRet);
//	bRet = pDirectory_04->AddCEntity(pFile_04);
//	assert(true == bRet);
//
//	std::cout << "**********************Dump of " << pDirectory_01->GetName() << " is as follows" << std::endl;
//	pDirectory_01->Dump();
//	std::cout << "**********************Dump of " << pDirectory_02->GetName() << " is as follows" << std::endl;
//	pDirectory_02->Dump();
//	std::cout << "**********************Dump of " << pDirectory_03->GetName() << " is as follows" << std::endl;
//	pDirectory_03->Dump();
//	std::cout << "**********************Dump of " << pDirectory_04->GetName() << " is as follows" << std::endl;
//	pDirectory_04->Dump();
//
//	size_t numOfEntities = pDirectory_01->NumOfCEntities();
//	std::cout << "num of entities in " << pDirectory_01->GetName() << " is: " << numOfEntities << std::endl;
//	numOfEntities = pDirectory_02->NumOfCEntities();
//	std::cout << "num of entities in " << pDirectory_02->GetName() << " is: " << numOfEntities << std::endl;
//	numOfEntities = pDirectory_03->NumOfCEntities();
//	std::cout << "num of entities in " << pDirectory_03->GetName() << " is: " << numOfEntities << std::endl;
//	numOfEntities = pDirectory_04->NumOfCEntities();
//	std::cout << "num of entities in " << pDirectory_04->GetName() << " is: " << numOfEntities << std::endl;
//
//	numOfEntities = pFile_01->NumOfCEntities();
//	std::cout << "num of entities in " << pFile_01->GetName() << " is: " << numOfEntities << std::endl;
//	numOfEntities = pFile_02->NumOfCEntities();
//	std::cout << "num of entities in " << pFile_02->GetName() << " is: " << numOfEntities << std::endl;
//	numOfEntities = pFile_03->NumOfCEntities();
//	std::cout << "num of entities in " << pFile_03->GetName() << " is: " << numOfEntities << std::endl;
//	numOfEntities = pFile_04->NumOfCEntities();
//	std::cout << "num of entities in " << pFile_04->GetName() << " is: " << numOfEntities << std::endl;
//
//	std::cout << "num of entities in pDirectory_01 before removing is: " << numOfEntities << std::endl;
//	bRet = pDirectory_01->RemoveCEntity(pDirectory_03);
//	assert(false == bRet);
//	numOfEntities = pDirectory_01->NumOfCEntities();
//	std::cout << "num of entities in pDirectory_01 after removing is: " << numOfEntities << std::endl;
//
//	std::cout << "num of entities in pDirectory_04 before removing is: " << numOfEntities << std::endl;
//	bRet= pDirectory_04->RemoveCEntity(pDirectory_03);
//	assert(true == bRet);
//	numOfEntities = pDirectory_04->NumOfCEntities();
//	std::cout << "num of entities in pDirectory_04 after removing is: " << numOfEntities << std::endl;
//
//	std::cout << "num of entities in pDirectory_01 before removing is: " << numOfEntities << std::endl;
//	bRet = pDirectory_01->RemoveCEntity(pFile_01);
//	assert(true == bRet);
//	numOfEntities = pDirectory_01->NumOfCEntities();
//	std::cout << "num of entities in pDirectory_01 after removing is: " << numOfEntities << std::endl;
//
//	return 1;
//}