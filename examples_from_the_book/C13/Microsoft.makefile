# From Thinking in C++, 2nd Edition
# At http://www.BruceEckel.com
# (c) Bruce Eckel 1999
# Copyright notice in Copyright.txt
# Automatically-generated MAKEFILE 
# For examples in directory C13
# using the Microsoft compiler
# Note: does not make files that will 
# not compile with this compiler
# Invoke with: make -f Microsoft.makefile

# Note: this requires the service Pack 3 from
# www.Microsoft.com for successful compilation!
# Also, you cannot run the "test" makefiles
# unless you go through and put 'return 0;' at
# the end of every main(), because VC++ does not
# follow the C++ Standard for defaulting return
# values from main().
CPP = cl
CPPFLAGS = -GX -GR
OFLAG = -o
.SUFFIXES : .obj .cpp .c
.cpp.obj :
	$(CPP) $(CPPFLAGS) -c $<
.c.obj :
	$(CPP) $(CPPFLAGS) -c $<

all: \
	MallocClass.exe \
	NewAndDelete.exe \
	BadVoidPointerDeletion.exe \
	PStashTest.exe \
	NewHandler.exe \
	Framis.exe \
	ArrayOperatorNew.exe \
	NoMemory.exe \
	PlacementOperatorNew.exe 

test: all 
	MallocClass.exe  
	NewAndDelete.exe  
	BadVoidPointerDeletion.exe  
	PStashTest.exe  
	NewHandler.exe  
	Framis.exe  
	ArrayOperatorNew.exe  
	NoMemory.exe  
	PlacementOperatorNew.exe  

bugs: \
	GlobalOperatorNew.exe 

MallocClass.exe: MallocClass.obj 
	$(CPP) $(OFLAG)MallocClass.exe MallocClass.obj 

NewAndDelete.exe: NewAndDelete.obj 
	$(CPP) $(OFLAG)NewAndDelete.exe NewAndDelete.obj 

BadVoidPointerDeletion.exe: BadVoidPointerDeletion.obj 
	$(CPP) $(OFLAG)BadVoidPointerDeletion.exe BadVoidPointerDeletion.obj 

PStashTest.exe: PStashTest.obj PStash.obj 
	$(CPP) $(OFLAG)PStashTest.exe PStashTest.obj PStash.obj 

NewHandler.exe: NewHandler.obj 
	$(CPP) $(OFLAG)NewHandler.exe NewHandler.obj 

GlobalOperatorNew.exe: GlobalOperatorNew.obj 
	$(CPP) $(OFLAG)GlobalOperatorNew.exe GlobalOperatorNew.obj 

Framis.exe: Framis.obj 
	$(CPP) $(OFLAG)Framis.exe Framis.obj 

ArrayOperatorNew.exe: ArrayOperatorNew.obj 
	$(CPP) $(OFLAG)ArrayOperatorNew.exe ArrayOperatorNew.obj 

NoMemory.exe: NoMemory.obj 
	$(CPP) $(OFLAG)NoMemory.exe NoMemory.obj 

PlacementOperatorNew.exe: PlacementOperatorNew.obj 
	$(CPP) $(OFLAG)PlacementOperatorNew.exe PlacementOperatorNew.obj 


MallocClass.obj: MallocClass.cpp ..\require.h 
NewAndDelete.obj: NewAndDelete.cpp Tree.h 
BadVoidPointerDeletion.obj: BadVoidPointerDeletion.cpp 
PStash.obj: PStash.cpp PStash.h ..\require.h 
PStashTest.obj: PStashTest.cpp PStash.h ..\require.h 
NewHandler.obj: NewHandler.cpp 
GlobalOperatorNew.obj: GlobalOperatorNew.cpp 
Framis.obj: Framis.cpp 
ArrayOperatorNew.obj: ArrayOperatorNew.cpp 
NoMemory.obj: NoMemory.cpp 
PlacementOperatorNew.obj: PlacementOperatorNew.cpp 

