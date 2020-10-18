APP := converter

CXX := g++
CXXFLAGS := -Wall -g -std=c++11 -stdlib=libc++

src := $(shell find . -name "*.cpp")
obj := $(patsubst %.cpp, %.o, $(src))

all: $(APP)

$(APP): $(obj)
	$(CXX) $(CXXFLAGS) -o $(APP) $(obj) 

depend: .depend

.depend: $(src)
	rm -f ./.depend
	$(CXX) $(CXXFLAGS) -MM $^>>./.depend;

clean:
	rm -f $(obj)

dist-clean:
	rm -f *~ .depend

include .depend