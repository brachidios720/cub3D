# cube-3d

## Mandatory part

- program name : cub3D
- turn in files : all your files
- makefile : all, clean, fclean, re, bonus
- argument : a map in format *.cub
- external function :
    - [ ] open
    - [ ] close
    - [ ] read
    - [ ] write
    - [ ] printf
    - [ ] malloc
    - [ ] free
    - [ ] perror
    - [ ] strerror
    - [ ] exit
    - [ ] gettimeofday
    - [ ] all function of the math library
    - [ ] all function of the minilibx

- libft authorized : yes

### Constraints

- you must use the minilibx
- the management of the window must remain smooth, changing to another window, minimizing, etc..
- display different wall texture (of our choice) that vary depending of which side the wall is facing
(north, south, east, west)
- the program must be able to set the floor and ceiling colors to two different ones
- the program display the image in a window and respects the following rules :
    - [ ] the left (<-) and right (->) arrow key must allow you to look left and right in the maze
    - [ ] the W, A, S, D keys must allow you to move the point of view through the maze (deplacement simulation)
    - [ ] pressing ESC must close the window and quit the program cleanly
    - [ ] Clicking on the red cross on the window's frame must close the window and quit the program cleanly
    - [ ] the use of the "image" of the minilibx is strongly recommended

- the program must take as a first argument a scene description file with the .cub extension
    - the map must be composed of only 6 possible characteres :
            - 0 for an empty space
            - 1 for a wall
            - N for the player start position and facing north
            - S for the player start position and facing south
            - E for the player start position and facing East
            - W for the plater start position and facing West
    - the map must be closed/surrounded by wall, if not the program must return an error
    - except for the map content, each type of element can be separated by one or more empty line(s)
    - except for the map content which always has to be the last, each type of element can be set
    in any order in the file
    - except for the map, each type of information from an element can be separated by one or more space(s)
    - the map must be parsed as it looks in the file. Space are a valid par of the map and are up to you
    to handle. You must be able to parse any kind of map, as long as it respects the rules of the map

    - each element (except the map) first information is the type idetifier (composed by one or two characteres),
    followed by all specific informations for each object in a strict order such as :
        - North texture :
            NO ./path_of_the_north_texture
            - identifier : NO 
            - path for the north texture
        - South texture :
            SO ./path_to_the_south_texture
            - identifier : SO
            - path to the south texture
        - West texture : 
            WE ./path_to_the_west_texture
            - identifier : WE
            - path to the west texture
        - East texture :
            EA ./path_to_the_east_texture
            - identifier : EA
            - path to the east texture
        - Floor color :
            F 220,100,0
            - identifier : F
            - R,G,B color in range [0,255] : 0,255,255 
        - Ceiling color :
            C 225,30,0
            - identifier : C 
            - R,G,B color in range [0,255] : 0,255,255 
    - example of the mandatory part with a minimalist .cub scene :

                    NO ./path_to_the_north_texture
                    SO ./path_to_the_south_texture
                    WE ./path_to_the_west_texture
                    EA ./path_to_the_east_texture

                    F 220,100,0
                    C 225,30,0

                            1111111111111111111111111
                            1000000000110000000000001
                            1011000001110000000000001
                            1001000000000000000000001
                    111111111011000001110000000000001
                    100000000011000001110111111111111
                    11110111111111011100000010001
                    11110111111111011101010010001
                    11000000110101011100000010001
                    10000000000000001100000010001
                    10000000000000001101010010001
                    11000001110101011111011110N0111
                    11110111 1110101 101111010001
                    11111111 1111111 111111111111

    - if any misconfiguration of any kinds is encountered in the file, the program
    must exit poperly an return "Error\n" followed by an explicit errir message of your choice


## Bonus 

- bonus list :
    - wall collisions
    - a minimap system
    - doors which can open and close
    - animated sprite
    - rotate the point of view with te mouse

### you are allowed to use other funcitons or add symbols on the map to complete the bonus part 
### as long as their use is justified during your evaluation. you are also allowed to modify the expected
### scene file format to fit your needs.
