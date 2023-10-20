_DEBUG = $(if $(DEBUG),-D DEBUG,)
_OPT = $(if $(OPT),-O3 -flto,)
CC = gcc
CFLAGS = -g -std=c99 -Wall -Werror $(_OPT) -I./include $(_DEBUG)

.PHONY: clean clean-img doc check-syntax compile-all launch-tests video

# rule to generate the doxygen documentation
doc:
	doxygen conf/doxygen.conf

# rule to remove all .o files and all executables
clean:
	- rm -f ./*.o
	- find ./ -executable -type f -delete

clean-wd:
	- del *.o
	- del *.exe


# rule to clean images and video
clean-img:
	- rm out/*.ppm *.mp4

clean-img-wd:
	- del out/*.ppm *.mp4


# compile rules
%.o: ./src/%.c
	$(CC) $(CFLAGS) -o $@ -c $^

%.o: ./tests/%.c
	$(CC) $(CFLAGS) -o $@ -c $^


# you should put all the .o files corresponding to your .c files as prerequisites of
# this rule (see examples)
# \ allows to go on the next line
check-syntax: example-main.o example-string.o read-file-formatted.o \
	      read-file-text.o write-fact.o test-dummy.o \
		  naive_universe.o naive_load.o naive_conway.o naive_ppm_writer.o \
		  test-naive-universe.o test-naive-load.o test-naive-conway.o test-naive-generate-image.o \
		  app-naive-loader.o app-naive-conway.o \
		  linked_list_cells.o list_universe.o list_loader.o list_conway.o list_ppm_writer.o \
		  test-linked-list-cells.o test-list-universe.o test-list-loader.o test-list-conway.o test-list-ppm-writer.o \
		  app-list-conway.o app-list-loader.o \

# put all the rules to build your applications and tests here (see examples)
example-main: example-main.o
	$(CC) $(CFLAGS) -o example-main example-main.o

example-string: example-string.o
	$(CC) $(CFLAGS) -o example-string example-string.o

read-file-formatted: read-file-formatted.o
	$(CC) $(CFLAGS) -o read-file-formatted read-file-formatted.o

read-file-text: read-file-text.o
	$(CC) $(CFLAGS) -o read-file-text read-file-text.o

write-fact: write-fact.o
	$(CC) $(CFLAGS) -o write-fact write-fact.o

app-ex-loader: app-ex-loader.o
	$(CC) $(CFLAGS) -o app-ex-loader app-ex-loader.o

test-dummy: test-dummy.o
	$(CC) $(CFLAGS) -o test-dummy test-dummy.o



test-naive-universe : test-naive-universe.o naive_universe.o 
	$(CC) $(CFLAGS) -o test-naive-universe test-naive-universe.o naive_universe.o

test-naive-load : test-naive-load.o naive_universe.o naive_load.o
	$(CC) $(CFLAGS) -o test-naive-load test-naive-load.o naive_universe.o naive_load.o

test-naive-conway : test-naive-conway.o naive_conway.o naive_load.o naive_universe.o naive_ppm_writer.o 
	$(CC) $(CFLAGS) -o test-naive-conway test-naive-conway.o naive_conway.o naive_load.o naive_universe.o naive_ppm_writer.o

test-naive-generate-image : test-naive-generate-image.o naive_ppm_writer.o naive_universe.o naive_load.o
	$(CC) $(CFLAGS) -o test-naive-generate-image test-naive-generate-image.o naive_ppm_writer.o naive_universe.o naive_load.o

app-naive-loader : app-naive-loader.o naive_universe.o naive_load.o
	$(CC) $(CFLAGS) -o app-naive-loader app-naive-loader.o naive_universe.o naive_load.o

app-naive-conway : app-naive-conway.o naive_conway.o naive_load.o naive_universe.o naive_ppm_writer.o
	$(CC) $(CFLAGS) -o app-naive-conway app-naive-conway.o naive_conway.o naive_load.o naive_universe.o naive_ppm_writer.o



test-linked-list-cells : test-linked-list-cells.o linked_list_cells.o
	$(CC) $(CFLAGS) -o test-linked-list-cells test-linked-list-cells.o linked_list_cells.o
	
test-list-universe: test-list-universe.o linked_list_cells.o list_universe.o
	$(CC) $(CFLAGS) -o test-list-universe test-list-universe.o linked_list_cells.o list_universe.o

test-list-loader: test-list-loader.o linked_list_cells.o list_universe.o list_loader.o
	$(CC) $(CFLAGS) -o test-list-loader test-list-loader.o linked_list_cells.o list_universe.o list_loader.o

test-list-conway: test-list-conway.o linked_list_cells.o list_universe.o list_conway.o list_loader.o list_ppm_writer.o
	$(CC) $(CFLAGS) -o test-list-conway test-list-conway.o linked_list_cells.o list_universe.o list_conway.o list_loader.o list_ppm_writer.o

test-list-ppm-writer: test-list-ppm-writer.o linked_list_cells.o list_universe.o list_loader.o list_ppm_writer.o
	$(CC) $(CFLAGS) -o test-list-ppm-writer test-list-ppm-writer.o linked_list_cells.o list_universe.o list_loader.o list_ppm_writer.o
	
app-list-loader: app-list-loader.o linked_list_cells.o list_universe.o list_loader.o
	$(CC) $(CFLAGS) -o app-list-loader app-list-loader.o linked_list_cells.o list_universe.o list_loader.o

app-list-conway: app-list-conway.o linked_list_cells.o list_universe.o list_conway.o list_loader.o list_ppm_writer.o
	$(CC) $(CFLAGS) -o app-list-conway app-list-conway.o linked_list_cells.o list_universe.o list_conway.o list_loader.o list_ppm_writer.o




# put all your applications and tests executables as prerequisite of this rule
# \ allows to go to the next line
compile-all: test-naive-universe test-naive-load test-naive-conway test-naive-generate-image\
			 app-naive-loader app-naive-conway test-linked-list-cells test-list-universe test-list-loader\
			 test-list-conway app-list-loader app-list-conway test-list-ppm-writer

comp-all-naive: test-naive-universe test-naive-load test-naive-conway test-naive-generate-image\
			 app-naive-loader app-naive-conway

comp-all-list: test-linked-list-cells test-list-universe test-list-loader test-list-conway\
			app-list-loader app-list-conway test-list-ppm-writer

compile-all-ex: example-main example-string read-file-formatted \
             read-file-text write-fact test-dummy \
			 test-naive-universe test-naive-load test-naive-conway test-naive-generate-image\
			 app-naive-loader app-naive-conway \
			 test-linked-list-cells test-list-universe test-list-loader test-list-conway\
	     	 app-ex-loader app-list-conway test-list-ppm-writer



# add all your test executables in the following variable. You should respect
# the order given in the project text
ALL_TESTS = test-dummy test-naive-universe test-naive-load test-naive-conway test_linked_list_cells test-list-loader test-list-conway\
			test-list-ppm-writer

launch-tests: $(ALL_TESTS)
	for x in $(ALL_TESTS); do ./$(x) --all; done

launch-tests-wd: $(ALL_TESTS)
	for %%x in ($(ALL_TESTS)) do .\%%x

# misc
WIDTH=1024
HEIGHT=768
FRAME=5
NAME=video.mp4

video: out
	mogrify -format png -resize $(WIDTH)X$(HEIGHT) -filter box -background white -extent $(WIDTH)X$(HEIGHT) -gravity center out/*.p*m
	ffmpeg -framerate $(FRAME) -i out/img-%03d.png -vcodec libx264 -vf format=yuv420p $(NAME)
	rm -f out/*.png

video-wd: out 
	magick out/img-* -format png -filter box -resize $(WIDTH)X$(HEIGHT) -background white -gravity center -extent $(WIDTH)X$(HEIGHT) out/img-%03d.png
	ffmpeg -framerate $(FRAME) -i out/img-%03d.png -vcodec libx264 -vf format=yuv420p $(NAME)
	- del .\out\*.png
	