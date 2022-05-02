FDF aka Fils De Fer aka Feira da Fruta
---

Estimated production time: 4 weeks

Libft and MLX Already included.

[Subject](https://cdn.intra.42.fr/pdf/pdf/24786/en.subject.pdf):page_facing_up:

---

2021/08/25 - Planning phase
Get project overview, learn the basics of pixel and minilibx.

**_PERSONAL_ Study roadmap**
1. Project Overview
   - Try to translate pdf from shitty english to something understandable
   - Think of how to proceed with mandatory part;
   - Read/understand bonus;
   - Laugh at it and get going with mandatory;
   - Actually, the bonus looks quite fun, tbh. Might aswell go for it.
   - Presently, need to say this: don't chose fdf over so-long/fractol if you don't plan on going for the bonus;

2. Minilibx
  - understang how to add minilibx to your project may be an effing struggle;
    - therefore, get to know wtf it is, how it works and what type os human sacrifices it likes the most;
	- find out what the heck are all those files we're given.

3. Rendering
   - open a window;
   - Draw 1 pixel;
     - Cartesian coordinates (x, y).
   - Draw a vertical line;
   - Draw a horizontal line;
   - Understand bresenhan's thingmajabba;
	 - there will actually be some major issues, namely how to organize your data.
	   - think how to organize your friggin data.
   - Draw a slanted line;
   - Draw a shitload of slanted lines;
   - Draw a slanted line that changes color accordingo to parameters h1 and h2;
   - Learn how to 8bit aRGB;
   - Color your pixels like a **motherfucking rainbow** so people can be **amazed** of how beautiful your lines are and regret chosing so_long over fdf.

4. Data structures
   - study structs;
   - study stack structures;
   - remember that libft_bonus? yeah. You'll likely use it here.

5. Coordinate Translation
   - Learn how to translate from 2d to isometric aka [math magic](https://math.stackexchange.com/questions/1601686/transforming-data-from-cartesian-plane-to-isometric-plane);
   - Learn how to elevate(Y) a point from X,Z in iso plane;
   - Find out some black magic to know the height of a pixel on a line and then translate it to a color (this should actually be easy);
   - If you by any means think of going for the bonus part (you actually should! Lots to be learned in there) get used to transformation matrices;

6. Map Parsing
   - **LOOK AT THE MFing MAPS!** there are several maps on the maps.zip file. Understand them. You'll like find some whose point values are something like 8,0xffddff. How you'll deal with it is open to interpretations. A crashing program, however, never is.
   - Think of a neat data sctructure to use along the program;
   - Study some map parsers;
   - DO NOT try to overoptimize your algoryth. If you need to iterate over the map a several times, it is ok.

7. Error handling
   - There are quite a lot of things that can go WRONG, better think of them beforehand to avoid possible headaches.

8. Just a few extra tips
   - Learn how to organize your shit. Read some Marie Kondo crap, use paper, use apps, as your brother to hold named stones tied with strings. I don't know and I don't care what's the best method, but, whatever floats your boat, DO IT! Just do it!
   - You might have to start over your project if (when) you find out you did some really stupid shit. Get over it quickly and restart asap. Sometimes it's easier to scrap all shit up than trying to fix it.
   - ~~You don't need to learn all that much math. I still use the calculator for 8x4.~~ You WILL need to learn math.

---

**ACTION!**

- Ok...So how the fuck do I use minilibx?
  - Ask around. Watch Intranet's videos. Try doing some shit.
    - Right, a fellow student put up a [.md version of minilibx](https://github.com/qst0/ft_libgfx/blob/master/man_mlx.md). It has not got any instructions on how to set it up though.
	- Might aswell sort out what's what on the resources we're given:
	  - subject.pdf : well....if you don't know what's that by now there's something really wrong going on.
	  - maps.zip : some .fdf maps with wich you'll test your program.
	  - IGNORE ALL OF THE FOLLOWING if on linux (all of this seem to be used solely for MacOS - wish I had known this before).
	  	- minilibx_macos_sierra_20161017.tgz : MacOS shit...?
	  	- minilibx_mms_20191025_beta.tgz : MORE MacOS shit, I guess
	  	- sources.tgz : contains the minilibx source files. But are made for MacOS
	  	- fdf : strange macos binary

	- X-window
	  - Required to display stuff on your screen. Required by minilibx. [Requires installing fell rituals - make sure to bring lots of goats.](https://thomasward.com/wsl2-x11/) Actually, screw this. Do the one below. On a VM if on windows.
	  - Try this handful [guide](https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html)
	    - Get MLX from here(https://github.com/42Paris/minilibx-linux)
		  - You'll have to install lots of libs and weird stuff they ask.
	  	    - you'll likely STILL need to install extra packages you have no idea what are for.
	  - intermission: just found out you can WIKI your project on github. Lots to do later :| Also, "Action" should likely be changed to devdiary or something
	  - MLX has a metric fuckton of compiling warnings...don't fret.
  - After some major testing and going through the previosly cited [guide](https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html) one can start to understand how to mlx by use. I'll try to explain the basics as plainly as I can (I wouldn't be able to explain it in a complex way anyway)
    - mlx_init() will do as it says and initialize mlx stuff. It basically turn the graphic engine on.
	- mlx_new_window() creates a pointer to a new window that is linked to our mlx_init()
	- mlx_new_image() creates an image we'll send to the previously created window. Notice that it creates an array. we'll access those to put our pixels in.
	- mlx_get_data_addr() just initializes some useful values we'll use to get our pixels on the image we just created
	- mlx_pixel_put() is shit. Don't use it .@harm-smits' function and explanation are way better. Check it out, it's worth it.
	- your custom pixel_put() will likely send pixels to an image address created from mlx_new_image.
	- mlx_put_image_to_window() does just what it says. Really. [It puts an image created by mlx_new_image(), edited by your pixel_put() into a window created by mlx_new_window.](https://www.youtube.com/watch?v=Ct6BUPvE2sM)
	- congrats, you now can start bashing your head against the brickwall that is placing pixels on a screen and the linear algebra that comes with it.

- Bresenham's
  -read [THIS.](https://www.middle-engine.com/blog/posts/2020/07/28/bresenhams-line-algorithm) It's a guide on how to do it omnidirectionally. Quite handful. Be wary of (x1==x2 && y1==y2) - Bad things may happen if you don't.

- Color gradient.
  - This one's fucked up and can be quite challenging. It might not look like it at first. Untill you realise that gradually changing from 0xff to x0f0 is quite the work.
  - Assuming that it's a 32bits int, we can infer it'll look like the following:
	- 0xaaRRGGBB - every 8 bits are used to represent a color value.
	  - aa : mlx_linux gives 0 fucks about alpha values. you can use this to store data. stonks! while this might seem really smart, it's a shitload of effort to make it work.
	  - RR : 65536 increments 1 in the red value, goes from 0 to 256. You can use bitshifts if you ~~want to look~~ are smart.
	  - GG : grows in increments of 256.
	  - BB : increments of 1
	- really. use bitwise operators.

- Error handling
  - exiting the process before cleaning all the mlx shit WILL result in leaks. **Keep that in mind.**
  - Likely, remember that your program must not have memory leaks. Saving every persistent allocated memmory address on a linked list stack and freeing them all before closing the program seems to be a good way to handle this. This way you'll only need to keep passing one more argument to your functions instead of juggling multiple pointers;
  - Wrong user input - how can someone fuck you up
    - no argv input;
	- multiple argv inputs;
    - file is not .fdf;
	- file IS .Fdf (check casing);
	- file is .fdf but name's fucked up - has chars c<33 or c>127;
	- file is not found;
	- user tries to use flags;
  - Map file
    - invalid inputs
	  - File has only 1 line;
	  - File has only 1 element/line;
	  - '0'<->'9' are valid characters;
	  - 'A'<->'F' and 'a'<->'f' are valid characters;
	  - 'x' is valid;
	  - 'X' is **not**;
	  - note that '-' also is a valid character;
	  - but it's up to you if you want to deal with the '+';
	  - not space character (c == 32 || (c > 8 && c < 14));
	  - map is an empty file;
	  - map is almost empty, being comprised only of '\n's;
	  - not an **int** or  **int,0xcolorhex** (no space character after the comma);
	  - hex is not well formated (overflow);
	  - int over/underflow;
	- line VALID input count differs from other lines;
	- map is too damn gigantic resulting in stack overflow
	  - I've found no really viable ways to dealing with this, but protecting your mallocs and if a line has more than 1000 elements (somebody would REALLY want to break your program), to return an error and exit the program.

- Data storage && map parsing
  - After giving it a shitload of thought, I'll use a big cluncky array to store my parsed map data. Format will be a pointer to a series of arrays: \*\*\*xyhc
	- Reading the whole the map and storing each line on a string inside a linked list seems to be a good move, that way I can just read the first line and know how many rows i'm getting; iterating over the list once gives me how many lines there'll be.
	- While memmory size is a concern, the largest maps on the test maps are about 2.5mb, therefore I'm giving a whole zero shits about it. Splurging on those strings to make the program somewhat faster.
  - parsing this will be a whole new pain in the ass.
	- update on this: I was right. :|
	  - terribly right :'(

- Config file for QoL
  - well, this one's not mandatory and is there only to make life easier at evaluation. It'll be used to adjust some values instead of hardcoding them. Its just a file that contains
	- default min height color in hex (0x00ffddff);
	- default max height color in hex (0x00ffddff);
	- window size length in pixels;
	- window size height in pixels;

- Runtime sequence (mandatory part)
  - Check args for errors;
  - Check config for errors;
  - Initialize config values;
  - Check map for errors;
  - Clean map of '\n's;
  - Initialize XYHC arrays;
  - Initialize MLX crap;
  - Light some mfing pixels :D ;
  - Initialize self destruction sequence (free everything).
  - either cry because valgrind shows leaks or rejoice that you finally finished this project;

- Development roadmap
  - **keep track of your heap allocation.**
  - Parse your map;
  - Load your map into an int \*\*\*array or struct \*\*array;
  - Start MLX, get some placeholder hooks and get the esc/click on red x working.
  - Design a new pixel_put function;
  - Create a function that puts a line of pixels from x1y1 to x2y2;
    - Study and implement bresenham's line(it's actually really easy);
  - Design a function to change the pixel's color according to the distance from x1y1 to x2y2;
  - get all coordinate values that you saved from your map and place them somewhere you can work as a 3d coordinate;
    - while you'll likely NOT use that big fucking array anymore, it's totally up to you wether to free it or not. Think ahead;
  - make 0,0 the CENTER of your map, this way whenever you apply a trasnformation matrix on it, it'll not go batshit crazy;
  - now if you've learned the power of linear algebra (aka transformation matrices) you'll either implement a function to deal with any kind of matrix or, transform a given matrix into code. Personally, going for the first - cub3d and miniRT will have to deal with a shitload of matrices (again, think ahead ;D);
    - This part is likely to be where most people will struggle the most, as the concepts we're to handle here are kinda of heavy fucking insane weight;
  - go freakin crazy with the matrices. Remeber those placeholder hooks? Time to put them to use :D
  - if your program crashes while zooming in, think about a division by 0;
  - I've boldened the 1st item of this list because it was important. Free your shit now. Also free the pointer created by mlx_init() as it will result in a leak;
  - Rejoice as you go from ape to a human after touching the black monolith that is fdf.



---

useful links:

https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html

https://github.com/qst0/ft_libgfx

https://www.middle-engine.com/blog/posts/2020/07/28/bresenhams-line-algorithm

https://math.stackexchange.com/questions/1601686/transforming-data-from-cartesian-plane-to-isometric-plane

https://linux.die.net/man/3/errno
