/*
This file is part of khmer, https://github.com/dib-lab/khmer/, and is
Copyright (C) 2016, The Regents of the University of California.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are
met:

    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.

    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.

    * Neither the name of the Michigan State University nor the names
      of its contributors may be used to endorse or promote products
      derived from this software without specific prior written
      permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
LICENSE (END)

Contact: khmer-project@idyll.org
*/
#include <progress_indicator.hh>

namespace khmer
{

namespace progress_indicator
{

ProgressIndicator::
ProgressIndicator()
    : update_interval(0), message("progress "), stream(std::cerr),
      _counter(0), _threshold(0)
{
}

ProgressIndicator::
ProgressIndicator(unsigned int interval, std::string msg, std::ostream& output)
    : update_interval(interval), message(msg), stream(output), _counter(0),
      _threshold(interval)
{
}

void ProgressIndicator::increment(unsigned int by)
{
    _counter += by;
    if(_threshold > 0 && _counter >= _threshold) {
        stream << message << _counter << std::endl;
        _threshold += update_interval;
    }
}

unsigned int ProgressIndicator::get_count()
{
    return _counter;
}

} // end namespace progress_indicator

} // end namespace khmer

// vim: set ft=cpp sts=4 sw=4 tw=80:
