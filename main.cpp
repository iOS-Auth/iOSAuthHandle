#include <iOSAuthRuntime/authorize.h>


// 获取偏移位置
const char* auth_handle_arg_offset(const char* _Arg, const char* _Key) noexcept
{
	auto 		vSize = strlen(_Key);
	if(0 == strncmp(_Arg, _Key, vSize))
	{
		return _Arg + vSize;
	}
	return nullptr;
}


// 入口
int main(int _Argc, char** _Argv)
{
	if(_Argc <= 1)
	{
		return AUTH_E_UNKNOWN_ERROR;
	}

	auto		vPipeName = std::string();
	for(auto vIndex = 0; vIndex < _Argc; ++vIndex)
	{
		if(auth_handle_arg_offset(_Argv[vIndex], "--pipe-name="))
		{
			vPipeName = auth_handle_arg_offset(_Argv[vIndex], "--pipe-name=");
		}
	}

	if(vPipeName.empty())
	{
		return AUTH_E_UNKNOWN_ERROR;
	}

	auto 		vError = auth_exec_sync_pipe(vPipeName.data());
	return vError;
}
