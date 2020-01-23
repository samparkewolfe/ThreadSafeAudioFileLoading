#pragma once

#include <string>
#include <memory>
#include "Buffer.hpp"

using namespace std;

namespace Load
{
    void audio(const string& fileAddress, shared_ptr<Buffer> bufferToFill);
}
