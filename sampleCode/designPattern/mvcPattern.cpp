#include <iostream>

class CModel
{
public:
	CModel(char* pName)
	{
		_value = 0;
	};
	~CModel() {};
	void SetValue(const int value)
	{
		_value = value;
	};
	void GetValue(int& rVal) const { rVal = _value; };
protected:
private:
	int _value;
	char _name[256];
};

class IView
{
public:
	virtual ~IView() {};
	virtual void Update() = 0;
protected:
	CModel *_pModel;
private:
};

class CView : public IView
{
public:
	~CView() {};
	void Update() {};
protected:
private:
};

class CStringView : public CView
{
public:
	CStringView(CModel* pModel)
	{
		_pModel = pModel;
	};
	~CStringView() {};
	void Update()
	{
		int i = 0;
		_pModel->GetValue(i);
		std::cout << "updated view from CStringView: ";
		for (int j = 0; j < i; ++j)
		{
			std::cout << "*";
		}
		std::cout << std::endl;
	};
protected:
private:
};

class CNumView : public IView
{
public:
	CNumView(CModel* pModel)
	{
		_pModel = pModel;
	};
	~CNumView() {};
	void Update()
	{
		int i = 0;
		_pModel->GetValue(i);
		std::cout << "updated view from CStringView: " << i << std::endl;
	};
protected:
private:
};

class CController
{
public:
	CController() {};
	~CController() {};
	void AddModel(CModel* pModel)
	{
		_pModel = pModel;
	};

	void AddViews(IView* pStringView, IView* pNumView)
	{
		_views[0] = pStringView;
		_views[1] = pNumView;
	};
	void Update()
	{
		_views[0]->Update();
		_views[1]->Update();
	};
	CModel* GetModel() const { return _pModel; };
protected:
private:
	CModel *_pModel;
	IView *_views[2];
};

class CCreateViewCommand
{
public:
	CCreateViewCommand() {};
	~CCreateViewCommand() {};
	IView* CreateView(const int typeOfView, CModel *pModel)
	{
		IView *pView = NULL;
		if (0 == typeOfView)
		{
			pView = new CStringView(pModel);
		}
		else if (1 == typeOfView)
		{
			pView = new CNumView(pModel);
		}

		return pView;
	};
protected:
private:
};

class CCreateModelCommand
{
public:
	CCreateModelCommand() {};
	~CCreateModelCommand() {};
	CModel* CreateModel()
	{
		CModel *pModel = new CModel("model number 1");
		return pModel;
	};
protected:
private:
};

class CUpdateCommand
{
public:
	CUpdateCommand(CController* pController)
	{
		_pController = pController;
	};
	~CUpdateCommand() {};
	void Update(const int value)
	{
		CModel* pModel = _pController->GetModel();
		pModel->SetValue(value);
		_pController->Update();
	};
protected:
private:
	CController *_pController;
};

int main()
{
	CCreateModelCommand createModel;
	CModel *pModel = createModel.CreateModel();
	CController controller;
	controller.AddModel(pModel);
	CCreateViewCommand createView;
	IView *pView_01 = createView.CreateView(0, pModel);
	IView *pView_02 = createView.CreateView(1, pModel);
	controller.AddViews(pView_01, pView_02);

	CUpdateCommand updateCommand(&controller);
	updateCommand.Update(2);
	updateCommand.Update(10);
	updateCommand.Update(4);
	updateCommand.Update(15);

	return 1;
}
