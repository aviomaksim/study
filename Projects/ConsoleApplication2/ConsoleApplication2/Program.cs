using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApplication2
{
    /// <remarks>Class <c>Program</c> Игра в морской бой..
    /// </remarks>
    class Program
    {
        //постоянные
        private const int _shipNear = 103;//рядом корабль
        private const int _shipHited = 102;//подбитый корабль
        private const int _shipMissed = 101;//промах
        private const int _shipNo = 100;//пустая клетка

        private const int _width = 10;//ширина и высота поля. Должно быть 10! Иначе программа может не коректно работать.
        private static Random _rnd;//Генератор случайных чисел
        private static int[] _enemyShipLives;//массив жизней врыжеских кораблей
        private static int _enemyLives;//Вражеские жизни
        private static int _playerLives;//Жизни игрока

        /// <summary>
        /// Создайте поле для игры Морской бой. 
        /// Корабли располагаются случайным образом или пользователь расставляет сам. 
        /// Также пользователь может вводить координаты корабля - программа выдает сообщения: Попал, Мимо, Убит
        /// </summary>
        /// <param name='args'>
        /// Действия с параметром отсутствуют.
        /// </param>
        static void Main(string[] args)
        {
            Console.WriteLine("---------");
            Console.WriteLine("igra >Morskoj boj<");
            Console.WriteLine("---------");
            Console.WriteLine("---------");
            Console.WriteLine("Pravila:");
            Console.WriteLine("1. polja 10x10");
            Console.WriteLine("2. Korabli: 1x4, 2x3, 3x2, 4x1");
            Console.WriteLine("   pervaja tsifra - kollichestvo");
            Console.WriteLine("   vtoraja tsifra - razmer");
            Console.WriteLine("3. Korabli ne mogut nahoditsja rjadom drug s drugom");
            Console.WriteLine("4. Hodim poocheredi");
            Console.WriteLine("5. Nachinaet igrok");
            Console.WriteLine("6. Esli popadaem v korabll, to hodim eshjo raz.");
            Console.WriteLine("7. Igra zakanchivaetsja kak tollko vse korabli budut podbiti!");
            Console.WriteLine("---------");

            Console.WriteLine("");


            int[][] playerArea = {//Итиализация матрици, в котором будут коробли игрока
                new int[_width],
                new int[_width],
                new int[_width],
                new int[_width],
                new int[_width],
                new int[_width],
                new int[_width],
                new int[_width],
                new int[_width],
                new int[_width]
            };

            int[][] enemyArea = {//Итиализация матрицы, в котором будут коробли врага
                new int[_width],
                new int[_width],
                new int[_width],
                new int[_width],
                new int[_width],
                new int[_width],
                new int[_width],
                new int[_width],
                new int[_width],
                new int[_width]
            };

            _enemyShipLives = new int[]{4,3,3,2,2,2,1,1,1,1};//жизни вржеских кораблей, от большого к малым
            _enemyLives = 20;//кол-во жизней у врага. Изначально равно сумме кол-ва жизней всех кораблей
            _playerLives = 20;//кол-во жизней у игрока. Изначально равно сумме кол-ва жизней всех кораблей

            _rnd = new Random();//создаём новые генератор случайных чисел

            //чистем поля
            ClearArea( playerArea );
            ClearArea( enemyArea );

            if(TakeIntValue( "Hotite sami rastavitt korabli? 0 - sluchaina, 1 - vruchnuju ", 1 )==0)//Вопрос игроку
            {
                PutRandomShips(playerArea);//расположение кораблей игрока в случайном порядке
            }else
            {
                Console.WriteLine("---------");
                Console.WriteLine("Proizvoditsja ruchnoj vvod koordinat korablej! Sledujte instruktsii.");
                Console.WriteLine("NB! Esli korabll nevozmozno razmestitt v zadonoj tochke, to programma podberjot druguju tochku (dvigajass v pravo i niz)");
                PutShips(playerArea);//расположение кораблей игрока вручную
            }

            PutRandomShips(enemyArea);//расположение кораблей врага в случайном порядке


            //---Процесс Игры---
            bool gameOver = false;//флаг окончания игры
            bool playerTurn = true;//флаг очерёдности
            string mess = " ";//буффер сообщений
            int x, y;//координаты

            while(!gameOver)//игра длиться пока флаг не поменяется
            {
                Console.Clear();//чистка экрана
                PrintTable(playerArea, enemyArea);//печать полей
                Console.WriteLine("");
                Console.WriteLine(mess);//печать сообщения
                if (playerTurn)//ход игрока
                {
                    //узнаём у игрока координаты атаки
                    x = TakeIntValue( "Navodka po gorizontali: " );
                    y = TakeIntValue( "Navodka po vertikali: " );


                    if( enemyArea[ x ][ y ] < _shipNo ) //попали
                    {
                        //уменьшаем жизнь коробля
                        _enemyShipLives[ enemyArea[ x ][ y ] ]--;
                        //уменьшаем жизнь врага
                        _enemyLives--;

                        if( _enemyShipLives[ enemyArea[ x ][ y ] ] < 1 ) //убит
                        {
                            mess = "Vrazeskij korabll [" + x + "][" + y + "] - ubit";
                        }
                        else //ранен
                        {
                            mess = "Vrazeskij korabll [" + x + "][" + y + "] - ranen";
                        }

                        enemyArea[ x ][ y ] = _shipHited;//меняем значение в матрице на "подбит"
                    }
                    else if( enemyArea[ x ][ y ] == _shipHited || enemyArea[ x ][ y ] == _shipMissed )//в эту точку уже стреляли
                    {
                        mess = "Vi uze streljali v to4ku [" + x + "][" + y + "] - Poprobujte druguju to4ku.";
                    }
                    else //промах
                    {
                        mess = "U vraga net korobleja v to4ke [" + x + "][" + y + "] - mimo";
                        enemyArea[x][y] = _shipMissed;//меняем значение в матрице на "промах"
                        playerTurn = false;//следующий ход будет за врагом
                    }
                }else//ход врага
                {
                    mess = mess + "\n";//добовляем следующийю страку в буффер сообщений

                    //задаём случайные координаты
                    x = _rnd.Next(0, playerArea.Length);
                    y = _rnd.Next(0, playerArea[0].Length);

                    //Далее мы будем пробигать по матрице до тех пор, пока не попадём в точку по которой ещё не стреляли
                    //Это на случай если случайная координата уже использовалась
                    //В этом случае будем двигаться в право-вниз
                    for (int j = 0; j < playerArea[0].Length; j++)
                    {
                        for( int i = 0; i < playerArea.Length; i++ )
                        {
                            if (playerArea[x][y] != _shipHited && playerArea[x][y] != _shipMissed)//в эту точку не стреляли
                            {
                                i = playerArea.Length;
                                j = playerArea[0].Length;
                            }
                            else//в эту точку уже стреляли
                            {
                                x++;
                                if (x >= playerArea.Length) x = 0;
                            }
                        }
                        if (playerArea[x][y] != _shipHited && playerArea[x][y] != _shipMissed)//в эту точку не стреляли
                        {
                            j = playerArea[0].Length;
                        }
                        else//в эту точку уже стреляли
                        {
                            y++;
                            if (y >= playerArea[0].Length) y = 0;
                        }
                        
                    }


                    if (playerArea[x][y] < _shipNo) //враг попал
                    {
                        _playerLives--;//уменьшаем жизни игрока

                        mess = mess + "Vrag popal v nash korabll [" + x + "][" + y + "]";
                        playerArea[x][y] = _shipHited;

                    }
                    else //враг промахнулся
                    {
                        mess = mess + "Vrag promazal [" + x + "][" + y + "]";
                        playerArea[x][y] = _shipMissed;
                        playerTurn = true;//следующий ход будет за игроком
                    }
                }

                

                if(_enemyLives < 1 )//победа за игроком
                {
                    //Игра закончина
                    //Чистим экран и показываем окончательное табло с поздравлением
                    Console.Clear();//чистка экрана
                    PrintTable(playerArea, enemyArea);//печать полей
                    Console.WriteLine("");
                    Console.WriteLine(mess);//печать сообщения
                    
                    gameOver = true;
                    Console.WriteLine("!!!!!!!!!!!! Pobeda !!!!!!!!!!");
                    Console.WriteLine("!!!!!!!!!!!! Pobeda !!!!!!!!!!");
                    Console.WriteLine("!!!!!!!!!!!! Pobeda !!!!!!!!!!");
                }
                else if (_playerLives < 1)//победа за врагом
                {
                    //Игра закончина
                    //Чистим экран и показываем окончательное табло с поздравлением
                    Console.Clear();//чистка экрана
                    PrintTable(playerArea, enemyArea);//печать полей
                    Console.WriteLine("");
                    Console.WriteLine(mess);//печать сообщения

                    gameOver = true;
                    Console.WriteLine("---- Progrish -----");
                    Console.WriteLine("---- Progrish -----");
                    Console.WriteLine("---- Progrish -----");
                }//в другом случае игра продолжается
            }

            Console.WriteLine("(Enter) - для выхода из программы.");
            Console.ReadLine();//Пауза экрана, чтобы посмотреть окончательный результат
        }

        /// <summary>
        /// Печать игрового табло
        /// </summary>
        /// <param name="area1">
        /// Матрица левого поля. Открытое поле.
        /// </param>
        /// <param name="area2">
        /// Матрица правого поля. Закрытое поле.
        /// </param>
        private static void PrintTable(int[][] area1, int[][] area2)
        {
            Console.Write("  ");
            for (int ii = 0; ii < area1[0].Length; ii++)
            {
                Console.Write(ii);
            }
            Console.Write("   ");
            for (int iii = 0; iii < area2[0].Length; iii++)
            {
                Console.Write(iii);
            }
            Console.WriteLine("");

            Console.Write(" /");
            for (int ii = 0; ii < area1[0].Length; ii++)
            {
                Console.Write("-");
            }
            Console.Write("   ");
            for (int iii = 0; iii < area2[0].Length; iii++)
            {
                Console.Write("-");
            }
            Console.WriteLine("\\");

            for (int i = 0; i < area1[0].Length; i++)
            {
                Console.Write( i + "|" );
                for (int j = 0; j < area1.Length; j++)
                {
                    PrintAllShips(area1[j][i]);//Печать элемента левого поля
                }
                Console.Write("|"+i+"|");
                for (int jj = 0; jj < area2.Length; jj++)
                {
                    PrintHitedShips(area2[jj][i]);//Печать элемента правого поля
                }
                Console.WriteLine("|" + i);
            }

            Console.Write(" \\");
            for (int ii = 0; ii < area1[0].Length; ii++)
            {
                Console.Write("-");
            }
            Console.Write("   ");
            for (int iii = 0; iii < area2[0].Length; iii++)
            {
                Console.Write("-");
            }
            Console.WriteLine("/");

            Console.Write("  ");
            for (int ii = 0; ii < area1[0].Length; ii++)
            {
                Console.Write(ii);
            }
            Console.Write("   ");
            for (int iii = 0; iii < area2[0].Length; iii++)
            {
                Console.Write(iii);
            }
            Console.WriteLine("");
        }

        /// <summary>
        /// Печать элемента во вражеском поле. Раскодирование элемента.
        /// </summary>
        /// <param name="n">
        /// Значение элемента.
        /// </param>
        private static void PrintHitedShips(int n)
        {
            char c = ' ';//То что будем печатать
            switch (n)
            {
                case _shipHited://Если подбит
                    {
                        c = 'X';
                        break;
                    }
                case _shipMissed://Если промах
                    {
                        c = '*';
                        break;
                    }
                default://Во всех други случаях - "состояние неизвестно"
                    {
                        c = ' ';
                        break;
                    }
            }

            Console.Write(c);//Печать элемента
        }

        /// <summary>
        /// Печать элемента в дружественном поле. Раскодирование элемента.
        /// </summary>
        /// <param name="n">
        /// Значение элемента.
        /// </param>
        private static void PrintAllShips(int n)
        {
            char c = ' ';//То что будем печатать
            switch(n)
            {
                case _shipNo://Если пусто, или
                case _shipNear://если рядом с кораблём
                {
                    c = ' ';
                    break;
                }
                case _shipHited://Если подбит
                {
                    c = 'X';
                    break;
                }
                case _shipMissed://Если сюда стреляли, но мимо
                {
                    c = '*';
                    break;
                }
                default://В други случаях будет знак коробля
                {
                    c = 'O';
                    break;
                }
            }

            Console.Write(c);//Печать элемента
        }

        /// <summary>
        /// Запрашивает число из консоли и проверяет корректность ввода.
        /// </summary>
        /// <param name='header'>
        /// Описание запроса.
        /// </param>
        /// <param name='max'>
        /// Максимальное значение (по умолчанию 10).
        /// </param>
        /// <param name='min'>
        /// Минимальное значение (по умолчанию 0).
        /// </param>
        /// <returns>
        /// Возвращает int число.
        /// </returns>
        public static int TakeIntValue(string header, int max = 10, int min = 0)
        {
            Console.WriteLine(header);

            int n;
            while (true)//return внутри цикла
            {
                n = 0;
                if ((Int32.TryParse(Console.ReadLine(), out n)))//Проверка - введено ли число типа Int32, или нет. Присвоение значения к "n".
                {
                    if (n > max || n < min)//Число не подходит
                    {
                        Console.WriteLine("Oshibka, chislo dolzno bitt ot {0} do {1}.", min, max);
                    }
                    else//Число подходит
                    {
                        return n;
                    }
                }
                else//Это не число типа Int32
                {
                    Console.WriteLine("Oshibke, nuzno vvesti tseloe chislo!");
                }
            }
        }

        /// <summary>
        /// Чистка матрицы. Все элементы будут равны значению "_shipNo"
        /// </summary>
        /// <param name="area">
        /// Матрица для чистки
        /// </param>
        private static void ClearArea(int[][] area)
        {
            for (int i = 0; i < area.Length; i++)
            {
                for (int j = 0; j < area[0].Length; j++)
                {
                    area[j][i] = _shipNo;
                }
            }
        }

        /// <summary>
        /// Вставляем в матрицу значения вручную
        /// </summary>
        /// <param name="area">
        ///   Обрабатываемая матрица
        /// </param>
        private static void PutShips( int[][] area )
        {
            int j = 0;
            int b, x, y;
            bool isVertical = false;//Оринтация корабля. Вертикально - Горизонтально.
            int shipId = 0;//Идетификатор кораблей. Каждая клетка корабля будет равна этому значению.
            for (int i = 4; i > 0; i--)//цикл. Максимальный размер корабля 4
            {
                j = 0;
                while (j < 5 - i)//цикл. Кол-во кораблей такого размера.
                {
                    //Если размер больше 1, то игрок вводит его оринтацию. Вертикально - Горизонтально.
                    b = i > 1 ? TakeIntValue( "Vvedite orintatsijui koroblja razmerom " + i + ". 0 - vertikallno, 1 - gorizontallno: ", 1 ) : 1;
                    
                    isVertical = b == 0;//Оринтация из цифры в bool

                    //Запрос у игрока координат
                    x = TakeIntValue("Vvedite raspolozenie livoj tochki koroblja razmerom "+i+" : ", _width-1);
                    y = TakeIntValue("Vvedite raspolozenie verhnej tochki koroblja razmerom " + i + " : ", _width-1);

                    //Ставим корабль в данную точку
                    //Если не удалось установить корабль - сообщение "програмный сбой"!
                    Console.WriteLine( PutShip( area, shipId, i, isVertical, x, y )
                                           ? " >Korabll razmeshjon."
                                           : " NB! Programmnij sboj! Nevozmozno razmestitt korabll. Perezapustite programmu." );

                    //переход к следующиму кораблю
                    j++;
                    shipId++;
                }
            }
        }

        /// <summary>
        /// Вставляем в матрицу значения в случайном порядке
        /// </summary>
        /// <param name="area">
        ///   Обрабатываемая матрица
        /// </param>
        private static void PutRandomShips( int[][] area )
        {
            int j;
            int shipId = 0;//Идетификатор кораблей. Каждая клетка корабля будет равна этому значению.

            for (int i = 4; i > 0; i--)//цикл. Максимальный размер корабля 4
            {
                j = 0;
                while (j < 5 - i)//цикл. Кол-во кораблей такого размера.
                {
                    PutShip(area, shipId, i);//Ставим корабль в данную точку

                    //переход к следующиму кораблю
                    j++;
                    shipId++;
                }
            }
        }

        /// <summary>
        /// Вставляем в матрицу конкретный корабль. Если с данной оринтацией корабля это не возможно, то меняем оринтация корабля.
        /// </summary>
        /// <param name="area">
        ///   Обрабатываемая матрица
        /// </param>
        /// <param name="shipId">
        ///   Идентификатор корабля
        /// </param>
        /// <param name="shipSize">
        ///   Размер корабля
        /// </param>
        /// <param name="isVertical">
        ///   Оринтация корабля
        /// </param>
        /// <param name="x">
        ///   x координата коробля
        /// </param>
        /// <param name="y">
        ///   y координата коробля
        /// </param>
        /// <returns>
        /// <c>true</c> - если процесс удачно закончился. <c>false</c> - если процесс не удачно закончился. 
        /// </returns>
        private static Boolean PutShip(int[][] area, int shipId, int shipSize, bool isVertical = true, int x = -1, int y = -1)
        {
            if (x < 0 && y < 0)//Если оринтация не задана - делаем случайной
            {
                isVertical = _rnd.Next(0, 2) == 1;
            }
            if (!PutShipOnWay(area, shipId, shipSize, isVertical, x , y))//если невозможно разместить карабль в таком положении
            {
                if (!PutShipOnWay(area, shipId, shipSize, !isVertical, x, y))//если невозможно разместить карабль и в другом положении
                {
                    return false;//невозможно разместить этот карабль. Выход из метода.
                }
            }
            return true;//карабль размещён. Выход из метода.
        }

        /// <summary>
        /// Вставляем в матрицу конкретный корабль.
        /// </summary>
        /// <param name="area">
        ///   Обрабатываемая матрица
        /// </param>
        /// <param name="shipId">
        ///   Идентификатор корабля
        /// </param>
        /// <param name="shipSize">
        ///   Размер корабля
        /// </param>
        /// <param name="isVertical">
        ///   Оринтация корабля
        /// </param>
        /// <param name="x">
        ///   x координата коробля
        /// </param>
        /// <param name="y">
        ///   y координата коробля
        /// </param>
        /// <returns>
        /// <c>true</c> - если процесс удачно закончился. <c>false</c> - если процесс не удачно закончился. 
        /// </returns>
        private static Boolean PutShipOnWay(int[][] area, int shipId, int shipSize, bool isVertical = true, int x = -1, int y = -1)
        {
            Boolean isOk = false;//Флаг
            if (isVertical)//Вертикальное размещение
            {
                //Если координаты не заданы , то генерируем случайные
                if (x < 0 && y < 0)
                {
                    x = _rnd.Next( 0, area.Length ); 
                    y = _rnd.Next( 0, area[ 0 ].Length - shipSize ); 
                }

                for (int j = 0; j < area[0].Length; j++)//цикл по горизонтали
                {
                    for (int i = 0; i < area.Length; i++)//цикл по вертикали
                    {
                        for (int ii = 0; ii < shipSize; ii++)//цикл по вертикали, проверда всей длины корабля
                        {
                            if (area[x][y + ii] != _shipNo)//корабль не возможно разместить в данной точке
                            {
                                ii = shipSize;
                                isOk = false;
                            }
                            else//корабль возможно разместить в данной точке
                            {
                                isOk = true;
                            }
                        }

                        //Если размещение возможно, то размещаем корабль.
                        //Иначе берём следующую координату.
                        //При размещении так же помечаются соседнии клетки коробля. Там запрещено ставить другой корабль.
                        if( isOk )
                        {
                            if (y - 1 >= 0)
                            {
                                if (x - 1 >= 0) area[x - 1][y - 1] = _shipNear;
                                area[x][y - 1] = _shipNear;
                                if (x + 1 < 10) area[x + 1][y - 1] = _shipNear;
                            }

                            for (int iii = 0; iii < shipSize; iii++)
                            {
                                if (x - 1 >= 0) area[x - 1][y + iii] = _shipNear;
                                area[x][y + iii] = shipId;
                                if (x + 1 < 10) area[x + 1][y + iii] = _shipNear;
                            }

                            if (y + 1 + shipSize >= 0)
                            {
                                if (x - 1 >= 0) area[x - 1][y + shipSize] = _shipNear;
                                area[x][y + shipSize] = _shipNear;
                                if (x + 1 < 10) area[x + 1][y + shipSize] = _shipNear;
                            }
                            return true;//Корабль размещён
                        }
                        x++;
                        if (x >= area.Length) x = 0;
                    }
                    y++;
                    if (y >= area[0].Length - shipSize) y = 0;
                }
            }
            else//Горизонтальное размещение
            {
                //Если координаты не заданы , то генерируем случайные
                if (x < 0 && y < 0)
                {
                    x = _rnd.Next( 0, area.Length - shipSize ); 
                    y = _rnd.Next( 0, area[ 0 ].Length ); 
                }

                for (int j = 0; j < area[0].Length; j++)//цикл по вертикали
                {
                    for (int i = 0; i < area.Length; i++)//цикл по горизонтали
                    {
                        for (int ii = 0; ii < shipSize; ii++)//цикл по горизонтали, проверда всей длины корабля
                        {
                            if (area[x + ii][y] != _shipNo)//корабль не возможно разместить в данной точке
                            {
                                ii = shipSize;
                                isOk = false;
                            }
                            else//корабль возможно разместить в данной точке
                            {
                                isOk = true;
                            }
                        }

                        //Если размещение возможно, то размещаем корабль.
                        //Иначе берём следующую координату.
                        //При размещении так же помечаются соседнии клетки коробля. Там запрещено ставить другой корабль.
                        if (isOk)
                        {
                            if (x - 1 >= 0)
                            {
                                if (y - 1 >= 0) area[x - 1][y - 1] = _shipNear;
                                area[x - 1][y] = _shipNear;
                                if (y + 1 < 10) area[x - 1][y + 1] = _shipNear;
                            }

                            for (int iii = 0; iii < shipSize; iii++)
                            {
                                if (y - 1 >= 0) area[x + iii][y - 1] = _shipNear;
                                area[x + iii][y] = shipId;
                                if (y + 1 < 10) area[x + iii][y + 1] = _shipNear;
                            }

                            if (x + shipSize >= 0)
                            {
                                if (y - 1 >= 0) area[x + shipSize][y - 1] = _shipNear;
                                area[x + shipSize][y] = _shipNear;
                                if (y + 1 < 10) area[x + shipSize][y + 1] = _shipNear;
                            }
                            return true;//Корабль размещён
                        }

                        x++;
                        if (x >= area.Length - shipSize) x = 0;
                    }
                    y++;
                    if (y >= area[0].Length) y = 0;

                }
            }

            return false;//Корабль не размещён
        }
    }
}
