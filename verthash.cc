#include <node.h>
#include <node_buffer.h>
#include <v8.h>
#include <stdint.h>

extern "C" {
	#include "h2.h"
}

using namespace node;
using namespace v8;

void verthash(const FunctionCallbackInfo<Value>& args) {

	Isolate* isolate = args.GetIsolate();
 	HandleScope scope(isolate);

	if (args.Length() < 2) {
	    isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Wrong number of arguments. Expected 2 (Hash, Datfile)", v8::NewStringType::kNormal).ToLocalChecked()));
	    return;
	}

	if (!Buffer::HasInstance(args[0])) {
            isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Invalid Argument. Hash must be a buffer", v8::NewStringType::kNormal).ToLocalChecked()));
            return;
	}

        if (!Buffer::HasInstance(args[1])) {
            isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Invalid Argument. Datfile must be a buffer", v8::NewStringType::kNormal).ToLocalChecked()));
            return;
        }


	unsigned char * datfileInput = (unsigned char *) Buffer::Data(args[0]);
	uint32_t datfileSize = Buffer::Length(args[0]);
	unsigned char * targetInput = (unsigned char *) Buffer::Data(args[1]);
	uint32_t targetSize = Buffer::Length(args[1]);

	unsigned char output[32];

	verthash_hash(datfileInput, datfileSize, targetInput, targetSize, output);

	args.GetReturnValue().Set(Buffer::Copy(isolate, (char *) output, 32).ToLocalChecked());
}


void init(Local<Object> exports) {
  NODE_SET_METHOD(exports, "hash", verthash);
}

NODE_MODULE(verthash, init)
