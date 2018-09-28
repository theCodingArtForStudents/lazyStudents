#include <stdio.h>
#include <stdlib.h> //rand()
#include <string.h> //memcpy()
#include <malloc.h>
#include <time.h>

char matrix[13][29];
char enemy_matrix[13][29];
char map[13][29] = {
    "  abcdefghijk     abcdefghijk ",
    " #----------#    #----------#",
    "0|       ",
    "1|       ",
    "2|       ",
    "3|       ",
    "4|       ",
    "5|       ",
    "6|       ",
    "7|       ",
    "8|       ",
    "9|       ",
    " #----------#    #----------#" };
char enemy_map[13][29] = {
    "  abcdefghijk     abcdefghijk ",
    " #----------#    #----------#",
    "0|       ",
    "1|       ",
    "2|       ",
    "3|       ",
    "4|       ",
    "5|       ",
    "6|       ",
    "7|       ",
    "8|       ",
    "9|       ",
    " #----------#    #----------#" };

void set (int);
void enemy_set (int);
int enemy_place (int, int, int, int);
int place (int, int, int, int);
void player_coords (int *, int *);
int symbol_to_coord(char c);
int simple_move (void);
int enemy_simple_move (void);
void init_map (void);
void init_enemy_map (void);


void main (void)
{
    int player_defeat=0, enemy_defeat=0, def=0, e_def=0;
    int i,j,m=0,n=0,r=3;
    float k=0.0;
    
    printf ("\n Wellcame to the Sea battle game! \n");
    printf ("\n You will playing whit computer. \n");
//    printf ("\n Не забывайте: удача улыбается лишь храбрым. \n");
//    printf ("\n Свистать всех наверх. Мы начинаем \n");
    /* Инициализация и последующее отображение игрового поля */
    init_map();
    
    for (i=0; i<13; i++)
    {
        printf("\n");
        for (j=0; j<29; j++)
            printf("%c", matrix[i][j]);
    }
    
    for (i=0; i<1000000000; i++)
        k *= 1.683;
    
    init_enemy_map();
    
    /* Организуется бесконечный цикл. Условие выхода - уничтожить все корабли */
    while (r > 0)
    {
        do {
            m = simple_move();
            for (i=0; i<13; i++)
            {
                printf("\n");
                for (j=0; j<29; j++)
                    printf("%c",matrix[i][j]);
            }
            
            for (i=0; i<13; i++)
                for (j=0; j<29; j++)
                    if (enemy_matrix[i][j] == 'X') def++;
            
            enemy_defeat = 20 - def;
            def = 0;
            // Условие окончания игры. Когда на карте не останется
            // ни одного символа 'X', переменная enemy_defeat будет равно 20
            // что соответствует условию выхода из цикла
            if (enemy_defeat == 20 )
            {
                printf("\n Player wins!\n");
                r = 0;
                break;
            }
        } while (m < 1);
        
        if (!r) break;
        
        m = 0;
        do {
            n = enemy_simple_move();
            
            for (i=0; i<13; i++)
            {
                printf("\n");
                for (j=0; j<29; j++)
                    printf("%c",matrix[i][j]);
            }
            
            for (i=0; i<13; i++)
                for (j=0; j<13; j++)
                    if (matrix[i][j] == 'X') def++;
            player_defeat = 20 - def;
            
            def = 0;
            // Условие окончания игры. Когда на карте не останется
            // ни одного символа 'X', переменная player_defeat будет равно 20
            // что соответствует условию выхода из цикла
            if (player_defeat == 20 )
            {
                printf("\n Player fails!\n");
                r = 0;
                break;
            }
        } while (n < 1);
        
        n = 0;
    }
}
// ------------------------------------------------------------
// получаем с клавиатуры координаты хода
void player_coords (int * a, int * b)
{
    char *str = malloc(sizeof(char) * 4);
    do {
        printf("\n Enter coord: "); scanf("%s", str);
        if( (str[0] >= '0') && (str[0] <= '9')){
            *a = atoi(&str[0]);
            *b = symbol_to_coord(str[1]);
        }else if((str[1] >= '0') && (str[1] <= '9')){
            *a = atoi(&str[1]);
            *b = symbol_to_coord(str[0]);
        }
        // Если пользователь ввел кривые координаты, его просят ввессти другие
        if (*a < 0 || *b < 0 || *a > 9 || *b > 9)
            printf ("\n Entering fail. Enter some other coords.\n");
    } while (*a < 0 || *b < 0 || *a > 9 || *b > 9);
    free(str);
}
// ------------------------------------------------------------
int symbol_to_coord(char c)
{
    switch (c) {
    case 'a':
    case 'A':
        return 0;
    case 'B':
    case 'b':
        return 1;
    case 'C':
    case 'c':
        return 2;
    case 'd':
    case 'D':
        return 3;
    case 'E':
    case 'e':
        return 4;
    case 'F':
    case 'f':
        return 5;
    case 'G':
    case 'g':
        return 6;
    case 'H':
    case 'h':
        return 7;
    case 'I':
    case 'i':
        return 8;
    case 'J':
    case 'j':
        return 9;

    default:
        return -1;
    }
}
// ------------------------------------------------------------
// Функция, котоая отвечает за ходы игрока
int simple_move (void)
{
    int i,j,k=0;
    int x,y,s,c;
    
    player_coords(&x, &y);
    
    // Все эти преобразования и, казалось бы, не имеюще
    // смысла действия, нужны из-за особенностей игрового поля
    i = s = y + 2;
    c = x + 2;
    j = x + 17;
    // Если попадание, то ставится '*'
    // как на игровое поле противника, так и на игровое поле игрока
    if (enemy_matrix[s][c] == '*' || enemy_matrix[s][c] == '0')
    {
        printf("\n You was shoot to that point. Shift coords! \n");
        player_coords(&x, &y);
    }
    if (enemy_matrix[s][c] == 'X')
    {
        k = 0;
        matrix[i][j] = '*';
        enemy_matrix[s][c] = '*';
    }
    // То же самое для промаха
    else
    {
        k = 1;
        matrix[i][j] = '0';
        enemy_matrix[s][c] = '0';
    }
    // Если пользователь попадает, то функция возвращает 0
    // Если промазывает - 1.
    // Это нужно для правильной очередности стрельбы, ведь в морском бое
    // попавший стреляет второй раз.
    return k;
}
// ------------------------------------------------------------
// Функция, которая отвечает за ходы компьютера
int enemy_simple_move (void)
{
    int i,j,s,c,q,y,x, p=1;
    int shot;
    
    do {
        x = rand() % 10;
        y = rand() % 10;
        i = s = y + 2;
        c = x + 2;
        j = x + 17;
        // Эта проверка нужна для того, чтобы компьютер не стрелял в одно и то же
        // место несколько раз. Если он уже стрелял в точку на игровом поле, то
        // его координаты генериируются снова
    } while (matrix[s][c] == '0' || matrix[s][c] == '*');
    
    if (matrix[s][c] == 'X')
    {
        shot = rand () % 4;
        q = 0;
        enemy_matrix[i][j] = '*';
        matrix[s][c] = '*';
        // Выше генерировалась случайная величина shot. Это направление
        // выстрела. Если компьютер попал один раз, то стреляет во второй
        // раз не куда попало, а в случайное место вокруг координат
        // попадания. Если он попадает второй раз, то продолжает стрелять
        // пока не упрется в пустое место или 0.
        switch (shot)
        {
        case 0:
        {
            while (matrix[s+p][c] == 'X')
            {
                enemy_matrix[i+p][j] = '*';
                matrix[s+p][c] = '*';
                p++;
            }
            if (matrix[s+p][c] == ' ')
            {
                enemy_matrix[i+p][j] = '0';
                matrix[s+p][c] = '0';
                q = 1;
            }
            break;
        }
        case 1:
        {
            while (matrix[s-p][c] == 'X')
            {
                enemy_matrix[i-p][j] = '*';
                matrix[s-p][c] = '*';
                p++;
            }
            if (matrix[s-p][c] == ' ')
            {
                enemy_matrix[i-p][j] = '0';
                matrix[s-p][c] = '0';
                q = 1;
            }
            break;
        }
        case 2:
        {
            while (matrix[s][c+p] == 'X')
            {
                enemy_matrix[i][j+p] = '*';
                matrix[s][c+p] = '*';
                p++;
            }
            if (matrix[s][c+p] == ' ')
            {
                enemy_matrix[i][j+p] = '0';
                matrix[s][c+p] = '0';
                q = 1;
            }
            break;
        }
        case 3:
        {
            while (matrix[s][c-p] == 'X')
            {
                enemy_matrix[i][j-p] = '*';
                matrix[s][c-p] = '*';
                p++;
            }
            if (matrix[s][c-p] == ' ')
            {
                enemy_matrix[i][j-p] = '0';
                matrix[s][c-p] = '0';
                q = 1;
            }
        }
        }
    }
    else
    {
        q = 1;
        enemy_matrix[i][j] = '0';
        matrix[s][c] = '0';
    }
    
    // Если компьютер попадает, то функция возвращает 0
    // Если промазывает - 1.
    // Это нужно для правильной очередности стрельбы, ведь в морском бое
    // кто попал, тот стреляет второй раз.
    return q;
}
// ------------------------------------------------------------
// Функции инициализации игрового поля
void init_map (void)
{
    set(4);
    set(3);
    set(3);
    set(2); // Тут происходит следующее:
    set(2); // Есть 4 матрицы: matrix, enemy_matrix, map и enemy_map
    set(2); // Для игрока инициализируется в map, а потом копируется в matrix.
    set(1); // Для компьютера инициализация происходит в enemy_map,
    set(1); // а потом это копируется в enemy_matrix. По другому почему-то
    set(1); // не работает. Я так и не смог решить эту проблему.
    set(1); // Вот такой вот костыль.
    memcpy(matrix,map,13*29*sizeof(char));
}
// ------------------------------------------------------------
void init_enemy_map (void)
{
    enemy_set(4);
    enemy_set(3);
    enemy_set(3);
    enemy_set(2);
    enemy_set(2);
    enemy_set(2);
    enemy_set(1);
    enemy_set(1);
    enemy_set(1);
    enemy_set(1);
    
    memcpy(enemy_matrix,enemy_map,13*29*sizeof(char));
}
// ------------------------------------------------------------
// В set() из функции init_map() передается deck - количество палуб корабля.
// В программе используется цикл while.
// Условие выполнения цикла - isset == 0; После того, как переменная isset != 0,
// выходим из цикла. Это означает, что корабль был успешно установлен.
void set (int deck)
{
    int i,j, isset = 0;
    int e, s,c, dir = 0;
    
    srand((unsigned)time(NULL));
    // В общем случае генерация координат проходит одинаково для всех
    // кораблей: генерируется случайное направление (dir), а также координаты
    // первой палубы. Корабль можно поставить горизонтально или вертикально,
    // а значит значение переменной dir может быть равно 0 или 1. Если dir = 0,
    // то корабль будет стоять горизонтально, если dir = 1 - вертикально.
    while (isset == 0)
    {
        // Для кораблей с разными палубами немного по разному
        // генерируются координаты расстановки. Так, четырехпалубный корабль
        // нельзя начинать ставить в (8;8), так как он тогда выйдет за пределы
        // поля, поэтому его возможности немного ограничены. В отличие от
        // однопалубного корабля, который может стоять где угодно
        switch (deck)
        {
        case 4:
        {
            dir = rand () % 2;
            s = 2 + rand () % 7;
            c = 2 + rand () % 7;
            break;
        }
        case 3:
        {
            dir = rand () % 2;
            s = 2 + rand () % 8;
            c = 2 + rand () % 8;
            break;
        }
        case 2:
        {
            dir = rand () % 2;
            s = 2 + rand () % 9;
            c = 2 + rand () % 9;
            break;
        }
        case 1:
        {
            dir = rand () % 2;
            s = 2 + rand () % 10;
            c = 2 + rand () % 10;
        }
        }
        
        switch (dir)
        {
        case 0:
        {
            e = place(s,c,dir,deck);
            if (e == 0)
            {
                for (i=0; i<deck; i++)
                    map[s][c+i] = 'X';
                isset = 1;
            }
            break;
        }
        case 1:
        {
            e = place (s,c,dir,deck);
            if (e == 0)
            {
                for (i=0; i<deck; i++)
                    map[s+i][c] = 'X';
                isset = 1;
            }
        }
        }
    }
}
// ------------------------------------------------------------
// Данная функция проверяет можно ли в принципе поставить
// корабль в данное место. Если можно, функция возвращает 0,
// если нельзя - 1
// Подробнее и с картинками работа данной функции
// рассмотрена в ПЗ
int place (int s, int c, int dir, int deck)
{
    int i, e=0;
    switch (dir)
    {
    case 0:
    {
        if (map[s][c] == 'X') e = 1;
        if (map[s-1][c-1] == 'X') e = 1;
        if (map[s-1][c+deck] == 'X') e = 1;
        if (map[s+1][c-1] == 'X') e = 1;
        if (map[s+1][c+deck] == 'X') e = 1;
        if (map[s][c-1] == 'X') e = 1;
        if (map[s][c+deck] == 'X') e = 1;
        for (i=0; i<deck; i++)
        {
            if (map[s-1][c+i] == 'X') e = 1;
            if (map[s+1][c+i] == 'X') e = 1;
        }
        break;
    }
    case 1:
    {
        if (map[s][c] == 'X') e = 1;
        if (map[s-1][c-1] == 'X') e = 1;
        if (map[s-1][c+1] == 'X') e = 1;
        if (map[s+deck][c-1] == 'X') e = 1;
        if (map[s+deck][c+1] == 'X') e = 1;
        if (map[s-1][c] == 'X') e = 1;
        if (map[s+deck][c] == 'X') e = 1;
        for (i = 0; i < deck; i++)
        {
            if (map[s+i][c-1] == 'X') e = 1;
            if (map[s+i][c+1] == 'X') e = 1;
        }
    }
    }
    return e;
}
// ------------------------------------------------------------
// Работа следующих функций абсолютно такая же, как и set() и place()
void enemy_set (int deck)
{
    srand((unsigned)time(NULL));
    int i,j, isset = 0;
    int e,s,c, dir = 0;
    
    while (!isset)
    {
        switch (deck)
        {
        case 4:
        {
            dir = rand () % 2;
            s = 2 + rand () % 7;
            c = 2 + rand () % 7;
            break;
        }
        case 3:
        {
            dir = rand () % 2;
            s = 2 + rand () % 8;
            c = 2 + rand () % 8;
            break;
        }
        case 2:
        {
            dir = rand () % 2;
            s = 2 + rand () % 9;
            c = 2 + rand () % 9;
            break;
        }
        case 1:
        {
            dir = rand () % 2;
            s = 2 + rand () % 10;
            c = 2 + rand () % 10;
        }
        }
        
        switch (dir)
        {
        case 0:
        {
            e = enemy_place(s,c,dir,deck);
            if (e == 0)
            {
                for (i=0; i<deck; i++)
                    enemy_map[s][c+i] = 'X';
                isset = 1;
            }
            break;
        }
        case 1:
        {
            e = enemy_place (s,c,dir,deck);
            if (e == 0)
            {
                for (i=0; i<deck; i++)
                    enemy_map[s+i][c] = 'X';
                isset = 1;
            }
        }
        }
    }
}
// ------------------------------------------------------------
int enemy_place (int s, int c, int dir, int deck)
{
    int i, e=0;
    
    switch (dir)
    {
    case 0:
    {
        if (enemy_map[s][c] == 'X') e = 1;
        if (enemy_map[s-1][c-1] == 'X') e = 1;
        if (enemy_map[s-1][c+deck] == 'X') e = 1;
        if (enemy_map[s+1][c-1] == 'X') e = 1;
        if (enemy_map[s+1][c+deck] == 'X') e = 1;
        if (enemy_map[s][c-1] == 'X') e = 1;
        if (enemy_map[s][c+deck] == 'X') e = 1;
        for ( i = 0; i < deck; i++)
        {
            if (enemy_map[s-1][c+i] == 'X') e = 1;
            if (enemy_map[s+1][c+i] == 'X') e = 1;
        }
        break;
    }
    case 1:
    {
        if (enemy_map[s][c] == 'X') e = 1;
        if (enemy_map[s-1][c-1] == 'X') e = 1;
        if (enemy_map[s-1][c+1] == 'X') e = 1;
        if (enemy_map[s+deck][c-1] == 'X') e = 1;
        if (enemy_map[s+deck][c+1] == 'X') e = 1;
        if (enemy_map[s-1][c] == 'X') e = 1;
        if (enemy_map[s+deck][c] == 'X') e = 1;
        for (i = 0; i < deck; i++)
        {
            if (enemy_map[s+i][c-1] == 'X') e = 1;
            if (enemy_map[s+i][c+1] == 'X') e = 1;
        }
    }
    }
    return e;
}
