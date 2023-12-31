DEBUG_FLAGS = -D _DEBUG -ggdb3 -std=c++2a -O0 -Wall -Wextra -Weffc++ -Waggressive-loop-optimizations -Wc++14-compat -Wmissing-declarations -Wcast-align -Wcast-qual -Wchar-subscripts -Wconditionally-supported -Wconversion -Wctor-dtor-privacy -Wempty-body -Wfloat-equal -Wformat-nonliteral -Wformat-security -Wformat-signedness -Wformat=2 -Winline -Wlogical-op -Wnon-virtual-dtor -Wopenmp-simd -Woverloaded-virtual -Wpacked -Wpointer-arith -Winit-self -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=2 -Wsuggest-attribute=noreturn -Wsuggest-final-methods -Wsuggest-final-types -Wsuggest-override -Wswitch-default -Wswitch-enum -Wsync-nand -Wundef -Wunreachable-code -Wunused -Wuseless-cast -Wvariadic-macros -Wno-literal-suffix -Wno-missing-field-initializers -Wno-narrowing -Wno-old-style-cast -Wno-varargs -Wstack-protector -fcheck-new -fsized-deallocation -fstack-protector -fstrict-overflow -flto-odr-type-merging -fno-omit-frame-pointer -Wstack-usage=8192 -pie -fPIE -fsanitize=address,alignment,bool,bounds,enum,float-cast-overflow,float-divide-by-zero,integer-divide-by-zero,nonnull-attribute,leak,null,object-size,return,returns-nonnull-attribute,shift,signed-integer-overflow,undefined,unreachable,vla-bound,vptr
RELEASE_FLAGS = -O2
SFML_FLAGS    = -lsfml-graphics -lsfml-window -lsfml-system

EXE_FILE = Exe/run

debug: color_debug vector_debug sphere_debug scene_debug
	g++ $(SFML_FLAGS) $(DEBUG_FLAGS) Src/main.cpp Obj/Vector.o Obj/Scene.o Obj/Sphere.o Obj/Color.o -o $(EXE_FILE)
release: color_release vector_release sphere_release scene_release
	g++ $(SFML_FLAGS) $(RELEASE_FLAGS) Src/main.cpp Obj/Vector.o Obj/Scene.o Obj/Sphere.o Obj/Color.o -o $(EXE_FILE)

vector_debug:
	g++ -c $(DEBUG_FLAGS) Src/Vector/Vector.cpp -o Obj/Vector.o
vector_release:
	g++ -c $(RELEASE_FLAGS) Src/Vector/Vector.cpp -o Obj/Vector.o

sphere_debug:
	g++ -c $(DEBUG_FLAGS) Src/Sphere/Sphere.cpp -o Obj/Sphere.o
sphere_release:
	g++ -c $(RELEASE_FLAGS) Src/Sphere/Sphere.cpp -o Obj/Sphere.o

scene_debug:
	g++ -c $(DEBUG_FLAGS) Src/Scene/Scene.cpp -o Obj/Scene.o
scene_release:
	g++ -c $(RELEASE_FLAGS) Src/Scene/Scene.cpp -o Obj/Scene.o

color_debug:
	g++ -c $(DEBUG_FLAGS) Src/Color/Color.cpp -o Obj/Color.o
color_release:
	g++ -c $(RELEASE_FLAGS) Src/Color/Color.cpp -o Obj/Color.o

run:
	./$(EXE_FILE)

preparation:
	mkdir Obj
	mkdir Exe

