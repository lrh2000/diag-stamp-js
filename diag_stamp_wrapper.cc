#include <napi.h>
#include "diag_stamp.h"

Napi::Value CalcDiagStampDiff(const Napi::CallbackInfo &info)
{
	Napi::Env env = info.Env();
	const char *error;
	uint64_t result;

	if (info.Length() != 2) {
		Napi::TypeError::New(env, "Wrong number of arguments")
			.ThrowAsJavaScriptException();
		return env.Null();
	}

	if (!info[0].IsString() || !info[1].IsString()) {
		Napi::TypeError::New(env, "Invalid argument type");
		return env.Null();
	}

	error = nullptr;
	result = calc_diag_stamp_diff(
		info[0].As<Napi::String>().Utf8Value().c_str(),
		info[1].As<Napi::String>().Utf8Value().c_str(), &error);
	if (error) {
		Napi::TypeError::New(env, error).ThrowAsJavaScriptException();
		return env.Null();
	}

	return Napi::Number::New(env, result);
}

Napi::Object Initialize(Napi::Env env, Napi::Object exports)
{
	return Napi::Function::New(env, CalcDiagStampDiff, "calcDiagStampDiff");
}

NODE_API_MODULE(diag_stamp, Initialize)
