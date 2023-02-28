<div align="center">
	<a href="https://www.42sp.org.br/">
		<img src="https://github.com/LucasDatilioCarderelli/42Cursus/blob/master/img/42-saopaulo.png" height=200>
	</a>
<h1> Cub3D </h1>
</div>

<h2 align="center">
	Project develop for <a href="https://github.com/LucasDatilioCarderelli/42Cursus"> 42Cursus </a>
</h2>

<p align="center">
	<a href="https://www.linkedin.com/in/lucasdatiliocarderelli/">
		<img alt="Linkedin" src="https://img.shields.io/badge/Lucas Datilio Carderelli-blue?style=flat&logo=Linkedin&logoColor=white" />
	</a>
	<a href="https://github.com/LucasDatilioCarderelli" alt="login intra">
		<img src="https://img.shields.io/badge/-ldatilio-gray?style=flat&logo=42&logoColor=white" />
	</a>
    &
	<a href="https://www.linkedin.com/in/viniciusnaziozeno/">
    	<img alt="Linkedin" src="https://img.shields.io/badge/
		Vinicius Naziozeno-blue?style=flat&logo=Linkedin&logoColor=white" />
  	</a>
	<a href="https://github.com/Vinicius-Santoro" alt="login intra">
    	<img src="https://img.shields.io/badge/-vnazioze-gray?style=flat&logo=42&logoColor=white" />
	</a>
	<br>
    <img src="https://img.shields.io/github/last-commit/LucasDatilioCarderelli/02-Pipex?color=blue">
	<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/LucasDatilioCarderelli/02-Pipex?color=blue" />
	<img alt="Number of lines of code" src="https://img.shields.io/tokei/lines/github/LucasDatilioCarderelli/02-Pipex?color=blue" />
</p>

Project 11: Cub3D - Eleventh project for the formation of software engineers at school 42 São Paulo.

	This project is inspired by the world-famous Wolfenstein 3D game. Our goal is to create a raycaster.

<br>

---

<br>

![gameplay](https://user-images.githubusercontent.com/83036509/219818886-1cb1f06d-862c-473e-a2bd-305c0960e93b.gif)
description: A gif of a player running in loop in a squared map

## **How to Run**

Clone the repository
```bash
git clone https://github.com/LucasDatilioCarderelli/11-cub3d
```

Run `./cub3D` followed by a `.cub` map path
```bash
./cub3D ./assets/maps/map42.cub
```

To compile yourself
- Run `make` to compile the game.
- Run `make play` to start the game.
- To clean objects files execute: `make clean`
- To clean executable file and objects: `make fclean`
- Recompile: `make re`

## **Map Configuration**

Example of a .cub file:

```
NO ./assets/Images/north.xpm
SO ./assets/Images/south.xpm  
WE ./assets/Images/west.xpm
EA ./assets/Images/east.xpm  

F 200,200,200
C 0,0,0

1111111111111111111111111111111111111
1000000000000000000000000000000000001
1001111000001111000001111111111111001
1001111000001111000001111111111111001
1001111000001111000001111111111111001
1001111000001111000000000000001111001
1001111111111111000001111111111111001
1001111111111111000001111111111111001
1000000000001111000001111111111111001
1000000000001111000001111000000000001
1000000000001111000001111111111111001
1000000000001111000001111111111111001
100000000000000000N000000000000000001
1111111111111111111111111111111111111
```

### Map description

The file must have 6 element identifiers:

| Identifier |        Description	    |
|:----------:|--------------------------|
|NO| Wall texture in the north direction|
|SO| Wall texture in the south direction|
|WE| Wall texture in the west direction	|
|EA| Wall texture in the east direction	|
|C | RGB color scale of the celling		|
|F | RGB color scale of the floor		|


The map construction is composed by the following characters:

- Walls: `'1'`
- Floor: `'0'`
- Empty: `' '`
- Initial player direction: `'N'`, `'S'`, `'W'` or `'E'`

#### Map Rules

- It must be completely surrounded by walls
- It must have a player

## How to play

- The `'→'` and `'←'`  keys of the keyboard allow you to look left and
right in the maze.
- The `'W'`, `'A'`, `'S'` and `'D'` keys allow you to move the point of view through
the maze.
- `'Esc'` key exits the game.

## Necessary concepts

- [O que é RayCasting?](docs/necessary_concepts/raycasting.md)
- [Interface gráfica utilizando a Linguagem C com MiniLibX](docs/necessary_concepts/interface.md)
- [RayCasting usando a Linguagem C](docs/necessary_concepts/raycasting-c.md)

### Details of the entire project

- [makefile](docs/project_details/makefile.md)
- [check_line.c](docs/project_details/check_line.md)
- [commands.c](docs/project_details/commands.md)
- [end_game.c](docs/project_details/end_game.md)
- [main.c](docs/project_details/main.md)
- [make_image.c](docs/project_details/make_image.md)
- [parse_map.c](docs/project_details/parse_map.md)
- [raycast.c](docs/project_details/raycast.md)
- [read_map.c](docs/project_details/read_map.md)

<br>

---

<br>

<a href="https://github.com/LucasDatilioCarderelli" alt="login intra">
    <img src="https://img.shields.io/badge/-ldatilio-gray?style=flat&logo=42&logoColor=white" />
</a>
<a href="https://www.linkedin.com/in/lucasdatiliocarderelli/">
    <img alt="Linkedin" src="https://img.shields.io/badge/Lucas Datilio Carderelli-blue?style=flat&logo=Linkedin&logoColor=white" /> 
</a>
&
<a href="https://github.com/Vinicius-Santoro" alt="login intra">
	<img src="https://img.shields.io/badge/-vnazioze-gray?style=flat&logo=42&logoColor=white" />
</a>
<a href="https://www.linkedin.com/in/viniciusnaziozeno/">
	<img alt="Linkedin" src="https://img.shields.io/badge/
	Vinicius Naziozeno-blue?style=flat&logo=Linkedin&logoColor=white" />
</a>
<br>