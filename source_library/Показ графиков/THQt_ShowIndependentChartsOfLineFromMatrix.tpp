template <class T> QString THQt_ShowIndependentChartsOfLineFromMatrix (T **VHQt_MatrixXY,int *VHQt_N_EveryCol,int VHQt_M, QString TitleChart, QString NameVectorX, QString NameVectorY,QString *NameLine, bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints)
{
    /*
Функция возвращает строку с выводом графиков из матрицы по точкам с HTML кодами. Для добавление в html файл.
Нечетные столбцы - это значения координат X графиков. Следующие за ними четные столбцы - соответствующие
значения Y. То есть графики друг от друга независимы.
Количество графиков равно половине столбцов в матрице.
Требует наличия в папке с html файлом файлы jsxgraph.css и jsxgraphcore.js из библиотеки JSXGraph.
Входные параметры:
 VHQt_MatrixXY - указатель на матрицу значений X и Н графиков;
 VHQt_N_EveryCol - количество элементов в каждом столбце (так как столбцы идут по парам, то число элементов в нечетном и
 следующем за ним четном столбце должны совпадать, например 10,10,5,5,7,7);
 VHQt_M - количество столбцов матрицы (должно быть четным числом конечно);
 TitleChart - заголовок графика;
 NameVectorX - название оси Ox;
 NameVectorY - название оси Oy;
 NameLine - указатель на вектор названий графиков (для легенды) количество элементов VHQt_M/2;
 ShowLine - показывать ли линию;
 ShowPoints - показывать ли точки;
 ShowArea - показывать ли закрашенную область под кривой;
 ShowSpecPoints - показывать ли специальные точки.
Возвращаемое значение:
 Строка с HTML кодами с выводимым графиком.
Примечание:
 Используются случайные числа, так что рекомендуется вызвать в программе инициализатор случайных чисел qsrand.
 Рекомендую так:
 qsrand(QDateTime::currentMSecsSinceEpoch () % 1000000);
*/
    QString VHQt_Result;//переменная итогового результата
    int i,j,k;

    //цвета
    QString CoordinateColor="#88969c";
    QString HighlightCoordinateColor="#3c7693";

    QString *Color=new QString [VHQt_M/2];
    for (j=0;j<VHQt_M/2;j++) Color[j]="#97bbcd";

    QString *HighlightColor=new QString [VHQt_M/2];
    for (j=0;j<VHQt_M/2;j++) HighlightColor[j]="#3c7693";

    QString *ColorArea=new QString [VHQt_M/2];
    for (j=0;j<VHQt_M/2;j++) ColorArea[j]="#97bbcd";

    QString *OpacityArea=new QString [VHQt_M/2];
    for (j=0;j<VHQt_M/2;j++) OpacityArea[j]="0.5";

    QString *StrokeWidth=new QString [VHQt_M/2];
    for (j=0;j<VHQt_M/2;j++) StrokeWidth[j]="2";

    QString *StrokeWidthPoints=new QString [VHQt_M/2];
    for (j=0;j<VHQt_M/2;j++) StrokeWidthPoints[j]="2";

    QString *FaceOfLine=new QString [VHQt_M/2];
    for (j=0;j<VHQt_M/2;j++) FaceOfLine[j]="o";

    if (VHQt_M/2==2)//если два графика
    {
        Color[1]="#cccccc";
        HighlightColor[1]="#7e7e7e";
        ColorArea[1]="#cccccc";
    }
    if ((VHQt_M/2==3)&&(ShowArea))//если три графика и показаны закрашенные области
    {
        Color[0]="#799bac";
        HighlightColor[0]="#9d2b24";
        ColorArea[0]="#799bac";
        OpacityArea[0]="0.5";

        Color[1]="#97bbcd";
        HighlightColor[1]="#3c7693";
        ColorArea[1]="#97bbcd";
        OpacityArea[1]="0.5";

        Color[2]="#cccccc";
        HighlightColor[2]="#7e7e7e";
        ColorArea[2]="#cccccc";
        OpacityArea[2]="0.5";
    }
    if ((VHQt_M/2==3)&&(!ShowArea))//если три графика и не показаны закрашенные области
    {
        Color[0]="#97bbcd";
        HighlightColor[0]="#3c7693";

        Color[1]="#4ac955";
        HighlightColor[1]="#2b8c34";

        Color[2]="#e06c65";
        HighlightColor[2]="#9d2b24";
    }
    if ((VHQt_M/2==4)&&(ShowArea))//если 4 графика и показаны закрашенные области
    {
        Color[0]="#799bac";
        HighlightColor[0]="#9d2b24";
        ColorArea[0]="#799bac";
        OpacityArea[0]="0.5";

        Color[1]="#83a6b7";
        HighlightColor[1]="#336278";
        ColorArea[1]="#83a6b7";
        OpacityArea[1]="0.5";

        Color[2]="#97bbcd";
        HighlightColor[2]="#3c7693";
        ColorArea[2]="#97bbcd";
        OpacityArea[2]="0.5";

        Color[3]="#cccccc";
        HighlightColor[3]="#7e7e7e";
        ColorArea[3]="#cccccc";
        OpacityArea[3]="0.5";
    }
    if ((VHQt_M/2==4)&&(!ShowArea))//если 4 графика и не показаны закрашенные области
    {
        Color[0]="#97bbcd";
        HighlightColor[0]="#3c7693";

        Color[1]="#4ac955";
        HighlightColor[1]="#2b8c34";

        Color[2]="#e7cc4c";
        HighlightColor[2]="#b49c28";

        Color[3]="#e06c65";
        HighlightColor[3]="#9d2b24";
    }
    if ((VHQt_M/2==5)&&(ShowArea))//если 4 графика и показаны закрашенные области
    {
        Color[0]="#799bac";
        HighlightColor[0]="#9d2b24";
        ColorArea[0]="#799bac";
        OpacityArea[0]="0.5";

        Color[1]="#83a6b7";
        HighlightColor[1]="#336278";
        ColorArea[1]="#83a6b7";
        OpacityArea[1]="0.5";

        Color[2]="#97bbcd";
        HighlightColor[2]="#3c7693";
        ColorArea[2]="#97bbcd";
        OpacityArea[2]="0.5";

        Color[3]="#adc2cd";
        HighlightColor[3]="#58839a";
        ColorArea[3]="#adc2cd";
        OpacityArea[3]="0.5";

        Color[4]="#cccccc";
        HighlightColor[4]="#7e7e7e";
        ColorArea[4]="#cccccc";
        OpacityArea[4]="0.5";
    }
    if ((VHQt_M/2==5)&&(!ShowArea))//если 5 графика и не показаны закрашенные области
    {
        Color[0]="#97bbcd";
        HighlightColor[0]="#3c7693";

        Color[1]="#4ac955";
        HighlightColor[1]="#2b8c34";

        Color[2]="#e7cc4c";
        HighlightColor[2]="#b49c28";

        Color[3]="#e06c65";
        HighlightColor[3]="#9d2b24";

        Color[4]="#9d50c8";
        HighlightColor[4]="#6a2b8d";
    }
    if ((VHQt_M/2==6)&&(ShowArea))//если 4 графика и показаны закрашенные области
    {
        Color[0]="#799bac";
        HighlightColor[0]="#9d2b24";
        ColorArea[0]="#799bac";
        OpacityArea[0]="0.5";

        Color[1]="#83a6b7";
        HighlightColor[1]="#336278";
        ColorArea[1]="#83a6b7";
        OpacityArea[1]="0.5";

        Color[2]="#97bbcd";
        HighlightColor[2]="#3c7693";
        ColorArea[2]="#97bbcd";
        OpacityArea[2]="0.5";

        Color[3]="#adc2cd";
        HighlightColor[3]="#58839a";
        ColorArea[3]="#adc2cd";
        OpacityArea[3]="0.5";

        Color[4]="#bec7cd";
        HighlightColor[4]="#5c7483";
        ColorArea[4]="#bec7cd";
        OpacityArea[4]="0.5";

        Color[5]="#cccccc";
        HighlightColor[5]="#7e7e7e";
        ColorArea[5]="#cccccc";
        OpacityArea[5]="0.5";
    }
    if ((VHQt_M/2==6)&&(!ShowArea))//если 5 графика и не показаны закрашенные области
    {
        Color[0]="#97bbcd";
        HighlightColor[0]="#3c7693";

        Color[1]="#4ac955";
        HighlightColor[1]="#2b8c34";

        Color[2]="#b5d24e";
        HighlightColor[2]="#8ca72c";

        Color[3]="#e7cc4c";
        HighlightColor[3]="#b49c28";

        Color[4]="#e06c65";
        HighlightColor[4]="#9d2b24";

        Color[5]="#9d50c8";
        HighlightColor[5]="#6a2b8d";
    }
    if ((VHQt_M/2==7)&&(ShowArea))//если 4 графика и показаны закрашенные области
    {
        Color[0]="#6a8795";
        HighlightColor[0]="#26576f";
        ColorArea[0]="#6a8795";
        OpacityArea[0]="0.5";

        Color[1]="#799bac";
        HighlightColor[1]="#9d2b24";
        ColorArea[1]="#799bac";
        OpacityArea[1]="0.5";

        Color[2]="#83a6b7";
        HighlightColor[2]="#336278";
        ColorArea[2]="#83a6b7";
        OpacityArea[2]="0.5";

        Color[3]="#97bbcd";
        HighlightColor[3]="#3c7693";
        ColorArea[3]="#97bbcd";
        OpacityArea[3]="0.5";

        Color[4]="#adc2cd";
        HighlightColor[4]="#58839a";
        ColorArea[4]="#adc2cd";
        OpacityArea[4]="0.5";

        Color[5]="#bec7cd";
        HighlightColor[5]="#5c7483";
        ColorArea[5]="#bec7cd";
        OpacityArea[5]="0.5";

        Color[6]="#cccccc";
        HighlightColor[6]="#7e7e7e";
        ColorArea[6]="#cccccc";
        OpacityArea[6]="0.5";
    }
    if ((VHQt_M/2==7)&&(!ShowArea))//если 5 графика и не показаны закрашенные области
    {
        Color[0]="#6250c9";
        HighlightColor[0]="#392b86";

        Color[1]="#97bbcd";
        HighlightColor[1]="#3c7693";

        Color[2]="#4ac955";
        HighlightColor[2]="#2b8c34";

        Color[3]="#b5d24e";
        HighlightColor[3]="#8ca72c";

        Color[4]="#e7cc4c";
        HighlightColor[4]="#b49c28";

        Color[5]="#e06c65";
        HighlightColor[5]="#9d2b24";

        Color[6]="#9d50c8";
        HighlightColor[6]="#6a2b8d";
    }
    if ((VHQt_M/2==8)&&(ShowArea))//если 4 графика и показаны закрашенные области
    {
        Color[0]="#6a8795";
        HighlightColor[0]="#26576f";
        ColorArea[0]="#6a8795";
        OpacityArea[0]="0.5";

        Color[1]="#799bac";
        HighlightColor[1]="#9d2b24";
        ColorArea[1]="#799bac";
        OpacityArea[1]="0.5";

        Color[2]="#83a6b7";
        HighlightColor[2]="#336278";
        ColorArea[2]="#83a6b7";
        OpacityArea[2]="0.5";

        Color[3]="#8eb1c3";
        HighlightColor[3]="#4d7183";
        ColorArea[3]="#8eb1c3";
        OpacityArea[3]="0.5";

        Color[4]="#97bbcd";
        HighlightColor[4]="#3c7693";
        ColorArea[4]="#97bbcd";
        OpacityArea[4]="0.5";

        Color[5]="#adc2cd";
        HighlightColor[5]="#58839a";
        ColorArea[5]="#adc2cd";
        OpacityArea[5]="0.5";

        Color[6]="#bec7cd";
        HighlightColor[6]="#5c7483";
        ColorArea[6]="#bec7cd";
        OpacityArea[6]="0.5";

        Color[7]="#cccccc";
        HighlightColor[7]="#7e7e7e";
        ColorArea[7]="#cccccc";
        OpacityArea[7]="0.5";
    }
    if ((VHQt_M/2==8)&&(!ShowArea))//если 5 графика и не показаны закрашенные области
    {
        Color[0]="#6250c9";
        HighlightColor[0]="#392b86";

        Color[1]="#97bbcd";
        HighlightColor[1]="#3c7693";

        Color[2]="#4ac955";
        HighlightColor[2]="#2b8c34";

        Color[3]="#b5d24e";
        HighlightColor[3]="#8ca72c";

        Color[4]="#e7cc4c";
        HighlightColor[4]="#b49c28";

        Color[5]="#e06c65";
        HighlightColor[5]="#9d2b24";

        Color[6]="#9d50c8";
        HighlightColor[6]="#6a2b8d";

        Color[7]="#c64f8f";
        HighlightColor[7]="#8d275e";
    }
    if ((VHQt_M/2==9)&&(ShowArea))//если 4 графика и показаны закрашенные области
    {
        Color[0]="#6a8795";
        HighlightColor[0]="#26576f";
        ColorArea[0]="#6a8795";
        OpacityArea[0]="0.5";

        Color[1]="#799bac";
        HighlightColor[1]="#9d2b24";
        ColorArea[1]="#799bac";
        OpacityArea[1]="0.5";

        Color[2]="#83a6b7";
        HighlightColor[2]="#336278";
        ColorArea[2]="#83a6b7";
        OpacityArea[2]="0.5";

        Color[3]="#8eb1c3";
        HighlightColor[3]="#4d7183";
        ColorArea[3]="#8eb1c3";
        OpacityArea[3]="0.5";

        Color[4]="#97bbcd";
        HighlightColor[4]="#3c7693";
        ColorArea[4]="#97bbcd";
        OpacityArea[4]="0.5";

        Color[5]="#adc2cd";
        HighlightColor[5]="#58839a";
        ColorArea[5]="#adc2cd";
        OpacityArea[5]="0.5";

        Color[6]="#b6c5cd";
        HighlightColor[6]="#617580";
        ColorArea[6]="#b6c5cd";
        OpacityArea[6]="0.5";

        Color[7]="#bec7cd";
        HighlightColor[7]="#5c7483";
        ColorArea[7]="#bec7cd";
        OpacityArea[7]="0.5";

        Color[8]="#cccccc";
        HighlightColor[8]="#7e7e7e";
        ColorArea[8]="#cccccc";
        OpacityArea[8]="0.5";
    }
    if ((VHQt_M/2==9)&&(!ShowArea))//если 5 графика и не показаны закрашенные области
    {
        Color[0]="#6250c9";
        HighlightColor[0]="#392b86";

        Color[1]="#97bbcd";
        HighlightColor[1]="#3c7693";

        Color[2]="#4ac955";
        HighlightColor[2]="#2b8c34";

        Color[3]="#b5d24e";
        HighlightColor[3]="#8ca72c";

        Color[4]="#e7cc4c";
        HighlightColor[4]="#b49c28";

        Color[5]="#e9ac4c";
        HighlightColor[5]="#946b2c";

        Color[6]="#e06c65";
        HighlightColor[6]="#9d2b24";

        Color[7]="#9d50c8";
        HighlightColor[7]="#6a2b8d";

        Color[8]="#c64f8f";
        HighlightColor[8]="#8d275e";
    }
    if ((VHQt_M/2>9)&&(ShowArea))//если 4 графика и показаны закрашенные области
    {
        double position;
        for (j=0;j<VHQt_M/2;j++)
        {
            position=j/double(VHQt_M/2);
            Color[j]=THQt_ColorFromGradient(position,"#6a8795","#cccccc");//"#537c90";
            HighlightColor[j]="#26576f";
            ColorArea[j]=THQt_ColorFromGradient(position,"#6a8795","#cccccc");//"#799bac";
            OpacityArea[j]="0.5";
        }
    }
    if ((VHQt_M/2>9)&&(!ShowArea))//если 4 графика и показаны закрашенные области
    {
        double position;
        for (j=0;j<VHQt_M/2;j++)
        {
            position=j/double(VHQt_M/2);
            Color[j]=THQt_AlphaBlendingColorToColor(0.4,THQt_GiveRainbowColorRGB(position),"#ffffff");
            HighlightColor[j]="#26576f";
        }
    }
    //по точкам пройдемся
    if (VHQt_M/2>=3)
    {
        FaceOfLine[1]="[]";
        StrokeWidthPoints[1]="2";

        FaceOfLine[2]="<>";
        StrokeWidthPoints[2]="3";
    }
    if (VHQt_M/2>=4)
    {
        FaceOfLine[3]="x";
        StrokeWidthPoints[3]="3";
    }
    if (VHQt_M/2>=5)
    {
        FaceOfLine[4]="+";
        StrokeWidthPoints[4]="3";
    }
    if (VHQt_M/2>=6)
    {
        FaceOfLine[5]="^";
        StrokeWidthPoints[5]="3";
    }
    if (VHQt_M/2>=7)
    {
        FaceOfLine[6]="v";
        StrokeWidthPoints[6]="3";
    }
    if (VHQt_M/2>=8)
    {
        FaceOfLine[7]=">";
        StrokeWidthPoints[7]="3";
    }
    if (VHQt_M/2>=9)
    {
        FaceOfLine[8]="<";
        StrokeWidthPoints[8]="3";
    }
    //когда уменьшать толщину линии
    if (VHQt_M/2>5)
        for (j=0;j<VHQt_M/2;j++)
        {
            StrokeWidth[j]="1";
            StrokeWidthPoints[j]=QString::number((StrokeWidthPoints[j].toInt())-1);
        }
    if (VHQt_M/2>9)//слишком много кривых
    {
        for (j=0;j<VHQt_M/2;j++)
        {
            FaceOfLine[j]="o";
            StrokeWidth[j]="1";
            StrokeWidthPoints[j]="1";
        }
    }

    //Подсчитаем максимальное число N
    int VHQt_N_Max;
    VHQt_N_Max = VHQt_N_EveryCol[0];
    for (j=0;j<VHQt_M/2;j++)
        if (VHQt_N_EveryCol[j*2]>VHQt_N_Max)
            VHQt_N_Max=VHQt_N_EveryCol[j*2];

    //посчитаем гарницы изменения параметров
    T MinX=VHQt_MatrixXY[0][0];
    for (j=0;j<VHQt_M/2;j++)
        for (int i=0;i<VHQt_N_EveryCol[j*2];i++)
            if (VHQt_MatrixXY[i][j*2]<MinX)
                MinX=VHQt_MatrixXY[i][j*2];

    T MaxX=VHQt_MatrixXY[0][0];
    for (j=0;j<VHQt_M/2;j++)
        for (int i=0;i<VHQt_N_EveryCol[j*2];i++)
            if (VHQt_MatrixXY[i][j*2]>MaxX)
                MaxX=VHQt_MatrixXY[i][j*2];

    T MinY=VHQt_MatrixXY[0][1];
    for (j=0;j<VHQt_M/2;j++)
        for (int i=0;i<VHQt_N_EveryCol[j*2+1];i++)
            if (VHQt_MatrixXY[i][j*2+1]<MinY)
                MinY=VHQt_MatrixXY[i][j*2+1];

    T MaxY=VHQt_MatrixXY[0][1];
    for (j=0;j<VHQt_M/2;j++)
        for (int i=0;i<VHQt_N_EveryCol[j*2+1];i++)
            if (VHQt_MatrixXY[i][j*2+1]>MaxY)
                MaxY=VHQt_MatrixXY[i][j*2+1];

    T LengthX=MaxX-MinX;
    T LengthY=MaxY-MinY;

    //посчитаем область графика, в которой все будет рисоваться
    T LeftXBoundingBox=MinX-LengthX/10.;
    T LeftYBoundingBox=MinY-LengthY/5.;
    T RightXBoundingBox=MaxX+LengthX/5.;
    T RightYBoundingBox=MaxY+LengthY/5.;

    if (MinX==MaxX) { LeftXBoundingBox-=1; LengthX=2; RightXBoundingBox+=1;}
    if (MinY==MaxY) { LeftYBoundingBox-=1; LengthY=2; RightYBoundingBox+=1;}

    QString SLeftXBoundingBox=QString::number(LeftXBoundingBox);
    QString SLeftYBoundingBox=QString::number(LeftYBoundingBox);
    QString SRightXBoundingBox=QString::number(RightXBoundingBox);
    QString SRightYBoundingBox=QString::number(RightYBoundingBox);
    SLeftXBoundingBox.replace(',', '.');
    SLeftYBoundingBox.replace(',', '.');
    SRightXBoundingBox.replace(',', '.');
    SRightYBoundingBox.replace(',', '.');

    //посчитаем, где будем рисовать оси
    T BeginXAxis=MinX;
    T BeginYAxis=MinY;
    T UpXAxis=BeginXAxis+1.;
    T UpYAxis=BeginYAxis+1.;
    QString SBeginXAxis=QString::number(BeginXAxis);
    QString SBeginYAxis=QString::number(BeginYAxis);
    QString SUpXAxis=QString::number(UpXAxis);
    QString SUpYAxis=QString::number(UpYAxis);
    SUpXAxis.replace(',', '.');
    SUpYAxis.replace(',', '.');

    VHQt_Result+="<!--Вывод графика-->\n";

    if ((!(TitleChart.trimmed().isEmpty())))
        VHQt_Result+="<h2>"+TitleChart+"</h2>";

    //имена объектов в графике
    QString UniqueName=HQt_RandomString(6);
    QString NameBox="Box"+UniqueName;
    QString NameBoard="Board"+UniqueName;
    QString NameAxisX="AxisX"+UniqueName;
    QString NameAxisY="AxisY"+UniqueName;

    QString *NameDataX=new QString[VHQt_M/2];
    QString *NameDataY=new QString[VHQt_M/2];
    QString *NameDataXArea=new QString[VHQt_M/2];
    QString *NameDataYArea=new QString[VHQt_M/2];
    QString *NameChart=new QString[VHQt_M/2];
    for (j=0;j<VHQt_M/2;j++) NameDataX[j]="DataX"+QString::number(j+1)+UniqueName;
    for (j=0;j<VHQt_M/2;j++) NameDataXArea[j]="DataX"+QString::number(j+1)+"Area"+UniqueName;
    for (j=0;j<VHQt_M/2;j++) NameDataY[j]="DataY"+QString::number(j+1)+UniqueName;
    for (j=0;j<VHQt_M/2;j++) NameDataYArea[j]="DataY"+QString::number(j+1)+"Area"+UniqueName;
    for (j=0;j<VHQt_M/2;j++) NameChart[j]="Chart"+QString::number(j+1)+UniqueName;

    //копируем во временный массив наши массивы, чтобы их не потревожить
    T **Temp_VHQt_MatrixXY;
    Temp_VHQt_MatrixXY=new double*[VHQt_N_Max];
    for (i=0;i<VHQt_N_Max;i++) Temp_VHQt_MatrixXY[i]=new double[VHQt_M];
    for (j=0;j<VHQt_M;j++)
        for (i=0;i<VHQt_N_EveryCol[j];i++)
            Temp_VHQt_MatrixXY[i][j]=VHQt_MatrixXY[i][j];

    //отсортируем массивы
    for (k=0;k<VHQt_M/2;k++)
    {
    for(i=VHQt_N_EveryCol[2*k]-1;i>0;i--)
        for(j=0;j<i;j++)
            if(Temp_VHQt_MatrixXY[j][2*k]>Temp_VHQt_MatrixXY[j+1][2*k])
            {
                    T x;
                    x=Temp_VHQt_MatrixXY[j+1][2*k];
                    Temp_VHQt_MatrixXY[j+1][2*k]=Temp_VHQt_MatrixXY[j][2*k];
                    Temp_VHQt_MatrixXY[j][2*k]=x;

                    x=Temp_VHQt_MatrixXY[j+1][2*k+1];
                    Temp_VHQt_MatrixXY[j+1][2*k+1]=Temp_VHQt_MatrixXY[j][2*k+1];
                    Temp_VHQt_MatrixXY[j][2*k+1]=x;
            }
    }

    //рисуем область графика и оси
    VHQt_Result+="<div id=\""+NameBox+"\" class=\"jxgbox\" style=\"width:600px; height:300px;\"></div>\n";
    VHQt_Result+="<script type=\"text/javascript\">\n";
    VHQt_Result+="var "+NameBoard+" = JXG.JSXGraph.initBoard('"+NameBox+"', {boundingbox: ["+SLeftXBoundingBox+", "+SRightYBoundingBox+", "+SRightXBoundingBox+", "+SLeftYBoundingBox+"], axis:false,keepaspectratio: false,showcopyright: false,showNavigation: false, zoom: {wheel: true}});\n";
    VHQt_Result+="var "+NameAxisX+" = "+NameBoard+".create('axis', [["+SBeginXAxis+", "+SBeginYAxis+"], ["+SUpXAxis+", "+SBeginYAxis+"]],{withLabel: true, name: '"+NameVectorX+"',label: {position:'lft',offset:[10,-21]}});\n";
    VHQt_Result+="var "+NameAxisY+" = "+NameBoard+".create('axis', [["+SBeginXAxis+", "+SBeginYAxis+"], ["+SBeginXAxis+", "+SUpYAxis+"]],{withLabel: true, name: '"+NameVectorY+"',label: { position:'lrt',offset: [20,0]}});\n";


    //соберем в массивы javascript данные точек
    QString *SDataX = new QString[VHQt_M/2];
    QString *SDataY = new QString[VHQt_M/2];

    for (j=0;j<VHQt_M/2;j++)
    {
        for (i=0;i<VHQt_N_EveryCol[2*j]-1;i++)
            SDataX[j]+=QString::number(Temp_VHQt_MatrixXY[i][2*j])+", ";
        SDataX[j]+=QString::number(Temp_VHQt_MatrixXY[VHQt_N_EveryCol[2*j+1]-1][2*j]);
    }

    for (j=0;j<VHQt_M/2;j++)
    {
        for (i=0;i<VHQt_N_EveryCol[2*j+1]-1;i++)
            SDataY[j]+=QString::number(Temp_VHQt_MatrixXY[i][2*j+1])+", ";
        SDataY[j]+=QString::number(Temp_VHQt_MatrixXY[VHQt_N_EveryCol[2*j+1]-1][2*j+1]);
    }

    //запишем массивы точек
    for (j=0;j<VHQt_M/2;j++)
    {
        VHQt_Result+="var "+NameDataX[j]+" = ["+SDataX[j]+"];\n";
        VHQt_Result+="var "+NameDataY[j]+" = ["+SDataY[j]+"];\n";
    }

    if (ShowArea)
    {
        //добавим точки для того, чтобы можно было закрасить сплошную область.

        for (j=0;j<VHQt_M/2;j++)
        {
            SDataX[j]=QString::number(Temp_VHQt_MatrixXY[0][2*j])+", "+SDataX[j]+", "+QString::number(Temp_VHQt_MatrixXY[VHQt_N_EveryCol[j*2]-1][2*j])+", "+QString::number(Temp_VHQt_MatrixXY[0][2*j]);
        }

        for (j=0;j<VHQt_M/2;j++)
            SDataY[j]=SBeginYAxis+", "+SDataY[j]+", "+SBeginYAxis+", "+SBeginYAxis;

        //нарисуем закрашенную область
        for (j=0;j<VHQt_M/2;j++)
        VHQt_Result+="var "+NameDataXArea[j]+" = ["+SDataX[j]+"];\n";
        for (j=0;j<VHQt_M/2;j++)
            VHQt_Result+="var "+NameDataYArea[j]+" = ["+SDataY[j]+"];\n";
        for (j=0;j<VHQt_M/2;j++)
            VHQt_Result+=NameBoard+".create('curve', ["+NameDataXArea[VHQt_M/2-1-j]+","+NameDataYArea[VHQt_M/2-1-j]+"],{strokeColor:'"+ColorArea[VHQt_M/2-1-j]+"',highlightStrokeColor:'"+ColorArea[VHQt_M/2-1-j]+"',strokeWidth:0,highlightStrokeWidth:0,dash:0, fillColor:'"+ColorArea[VHQt_M/2-1-j]+"',highlightFillColor:'"+ColorArea[VHQt_M/2-1-j]+"',fillOpacity:"+OpacityArea[VHQt_M/2-1-j]+",highlightFillOpacity:"+OpacityArea[VHQt_M/2-1-j]+"});\n";
    }

    if ((ShowPoints)&&(ShowLine))
    {
        //Нарисуем график
        for (j=0;j<VHQt_M/2;j++)
        {
            VHQt_Result+="var "+NameChart[VHQt_M/2-1-j]+"= "+NameBoard+".createElement('chart', ["+NameDataX[VHQt_M/2-1-j]+","+NameDataY[VHQt_M/2-1-j]+"], {chartStyle:'line,point'});\n";
            VHQt_Result+=NameChart[VHQt_M/2-1-j]+"[0].setProperty('strokeColor:"+Color[VHQt_M/2-1-j]+"','highlightStrokeColor:"+HighlightColor[VHQt_M/2-1-j]+"','strokeWidth:"+StrokeWidth[VHQt_M/2-1-j]+"');\n";
            VHQt_Result+="for(var i=0; i<"+QString::number(VHQt_N_EveryCol[VHQt_M-1-2*j])+";i++) \n";
            VHQt_Result+="    {\n";
            VHQt_Result+="    "+NameChart[VHQt_M/2-1-j]+"[1][i].setProperty({strokeColor:'"+Color[VHQt_M/2-1-j]+"',highlightStrokeColor:'"+HighlightColor[VHQt_M/2-1-j]+"',fillColor:'white',highlightFillColor:'white',face:'"+FaceOfLine[VHQt_M/2-1-j]+"', size:"+StrokeWidthPoints[VHQt_M/2-1-j]+", strokeWidth:'"+StrokeWidth[VHQt_M/2-1-j]+"pt'});\n";
            VHQt_Result+="    }\n";
        }
    }

    if ((ShowPoints)&&(!ShowLine))
    {
        //Нарисуем точки
        for (j=0;j<VHQt_M/2;j++)
        {
            VHQt_Result+="var "+NameChart[VHQt_M/2-1-j]+"= "+NameBoard+".createElement('chart', ["+NameDataX[VHQt_M/2-1-j]+","+NameDataY[VHQt_M/2-1-j]+"], {chartStyle:'line,point'});\n";
            VHQt_Result+=NameChart[VHQt_M/2-1-j]+"[0].setProperty('strokeColor:"+Color[VHQt_M/2-1-j]+"','highlightStrokeColor:"+HighlightColor[VHQt_M/2-1-j]+"','strokeWidth:0');\n";
            VHQt_Result+="for(var i=0; i<"+QString::number(VHQt_N_EveryCol[VHQt_M-1-2*j])+";i++) \n";
            VHQt_Result+="    {\n";
            VHQt_Result+="    "+NameChart[VHQt_M/2-1-j]+"[1][i].setProperty({strokeColor:'"+Color[VHQt_M/2-1-j]+"',highlightStrokeColor:'"+HighlightColor[VHQt_M/2-1-j]+"',fillColor:'white',highlightFillColor:'white',face:'"+FaceOfLine[VHQt_M/2-1-j]+"', size:"+StrokeWidthPoints[VHQt_M/2-1-j]+", strokeWidth:'"+StrokeWidth[VHQt_M/2-1-j]+"pt'});\n";
            VHQt_Result+="    }\n";
        }
    }

    if ((!ShowPoints)&&(ShowLine))
    {
        //Нарисуем только линию
        for (j=0;j<VHQt_M/2;j++)
        {
            VHQt_Result+="var "+NameChart[VHQt_M/2-1-j]+"= "+NameBoard+".createElement('chart', ["+NameDataX[VHQt_M/2-1-j]+","+NameDataY[VHQt_M/2-1-j]+"], {chartStyle:'line'});\n";
            VHQt_Result+=NameChart[VHQt_M/2-1-j]+"[0].setProperty('strokeColor:"+Color[VHQt_M/2-1-j]+"','highlightStrokeColor:"+HighlightColor[VHQt_M/2-1-j]+"','strokeWidth:"+StrokeWidth[VHQt_M/2-1-j]+"');\n";
        }
    }

    if (ShowSpecPoints)
    {
        //Теперь проставим точки
        //Нулевая точка
        VHQt_Result+=NameBoard+".create('point',["+SBeginXAxis+","+SBeginYAxis+"], {strokeColor:'"+CoordinateColor+"',highlightStrokeColor:'"+HighlightCoordinateColor+"',fillColor:'white',highlightFillColor:'white',strokeWidth:'2pt',face:'o', size:1, name:'Min<sub>x</sub> = "+SBeginXAxis+", Min<sub>y</sub> = "+SBeginYAxis+"',label:{fontsize:10}});\n";
        //Максимальная по Y
        VHQt_Result+=NameBoard+".create('point',["+SBeginXAxis+","+QString::number(MaxY)+"], {strokeColor:'"+CoordinateColor+"',highlightStrokeColor:'"+HighlightCoordinateColor+"',fillColor:'white',highlightFillColor:'white',strokeWidth:'2pt',face:'o', size:1, name:'Max<sub>y</sub> = "+QString::number(MaxY)+"',label:{fontsize:10}});\n";
        //Максимальная по X
        VHQt_Result+=NameBoard+".create('point',["+QString::number(MaxX)+","+SBeginYAxis+"], {strokeColor:'"+CoordinateColor+"',highlightStrokeColor:'"+HighlightCoordinateColor+"',fillColor:'white',highlightFillColor:'white',strokeWidth:'2pt',face:'o', size:1, name:'Max<sub>x</sub> = "+QString::number(MaxX)+"',label:{fontsize:10}});\n";
    }

    VHQt_Result+="</script>\n";

    // ЛЕГЕНДА
    int NameLineHowManyEmpty=0;
    for (j=0;j<VHQt_M/2;j++) if (NameLine[j].trimmed().isEmpty()!=true) NameLineHowManyEmpty++;

    if (NameLineHowManyEmpty!=0)
    {
        //имена объектов в легенде
        QString UniqueNameLegend=HQt_RandomString(6);
        QString NameBoxNameLegend="BoxLegend"+UniqueNameLegend;
        QString NameBoardLegend="BoardLegend"+UniqueNameLegend;
        QString NameDataXLegend="DataXLegend"+UniqueNameLegend;

        QString *NameDataYLegend= new QString[VHQt_M/2];
        QString *NameChartLegend= new QString[VHQt_M/2];
        QString *NameTextLegend= new QString[VHQt_M/2];

        for (j=0;j<VHQt_M/2;j++) NameDataYLegend[j]="DataY"+QString::number(j+1)+"Legend"+UniqueNameLegend;
        for (j=0;j<VHQt_M/2;j++) NameChartLegend[j]="Chart"+QString::number(j+1)+"Legend"+UniqueNameLegend;
        for (j=0;j<VHQt_M/2;j++) NameTextLegend[j]="Text"+QString::number(j+1)+"Legend"+UniqueNameLegend;


        //рисуем область графика и оси
        VHQt_Result+="<div id=\""+NameBoxNameLegend+"\" class=\"jxgbox\" style=\"width:600px; height:"+QString::number(50*(VHQt_M/2))+"px;\"></div>\n";
        VHQt_Result+="<script type=\"text/javascript\">\n";
        SLeftXBoundingBox="0";
        SRightYBoundingBox=QString::number(VHQt_M/2+1);
        SRightXBoundingBox="11.5";
        SLeftYBoundingBox="0";
        VHQt_Result+="var "+NameBoardLegend+" = JXG.JSXGraph.initBoard('"+NameBoxNameLegend+"', {boundingbox: ["+SLeftXBoundingBox+", "+SRightYBoundingBox+", "+SRightXBoundingBox+", "+SLeftYBoundingBox+"], axis:false,keepaspectratio: false,showcopyright: false,showNavigation: false, zoom: {wheel: false}});\n";

        //соберем в массивы javascript данные точек
        QString SDataX="1, 2";

        for (j=0;j<VHQt_M/2;j++) SDataY[j]=QString::number(VHQt_M/2-j)+", "+QString::number(VHQt_M/2-j);

        if ((ShowPoints)&&(!ShowLine))
        {
            //на одну точку больше
            SDataX="1, 1.5, 2";
            for (j=0;j<VHQt_M/2;j++) SDataY[j]=QString::number(VHQt_M/2-j)+", "+QString::number(VHQt_M/2-j)+", "+QString::number(VHQt_M/2-j);
        }

        //запишем массивы точек

        VHQt_Result+="var "+NameDataXLegend+" = ["+SDataX+"];\n";
        for (j=0;j<VHQt_M/2;j++)
            VHQt_Result+="var "+NameDataYLegend[j]+" = ["+SDataY[j]+"];\n";

        if ((ShowPoints)&&(ShowLine))
        {
            //Нарисуем график
            for (j=0;j<VHQt_M/2;j++)
            {
                VHQt_Result+="var "+NameChartLegend[VHQt_M/2-1-j]+"= "+NameBoardLegend+".createElement('chart', ["+NameDataXLegend+","+NameDataYLegend[VHQt_M/2-1-j]+"], {chartStyle:'line,point'});\n";
                VHQt_Result+=NameChartLegend[VHQt_M/2-1-j]+"[0].setProperty('strokeColor:"+Color[VHQt_M/2-1-j]+"','highlightStrokeColor:"+HighlightColor[VHQt_M/2-1-j]+"','strokeWidth:"+StrokeWidth[VHQt_M/2-1-j]+"');\n";
                VHQt_Result+="for(var i=0; i<"+QString::number(2)+";i++) \n";
                VHQt_Result+="    {\n";
                VHQt_Result+="    "+NameChartLegend[VHQt_M/2-1-j]+"[1][i].setProperty({strokeColor:'"+Color[VHQt_M/2-1-j]+"',highlightStrokeColor:'"+HighlightColor[VHQt_M/2-1-j]+"',fillColor:'white',highlightFillColor:'white',face:'"+FaceOfLine[VHQt_M/2-1-j]+"', size:"+StrokeWidthPoints[VHQt_M/2-1-j]+", strokeWidth:'"+StrokeWidth[VHQt_M/2-1-j]+"pt'});\n";
                VHQt_Result+="    }\n";
            }
        }

        if ((ShowPoints)&&(!ShowLine))
        {
            //Нарисуем точки
            for (j=0;j<VHQt_M/2;j++)
            {
                VHQt_Result+="var "+NameChartLegend[VHQt_M/2-1-j]+"= "+NameBoardLegend+".createElement('chart', ["+NameDataXLegend+","+NameDataYLegend[VHQt_M/2-1-j]+"], {chartStyle:'line,point'});\n";
                VHQt_Result+=NameChartLegend[VHQt_M/2-1-j]+"[0].setProperty('strokeColor:"+Color[VHQt_M/2-1-j]+"','highlightStrokeColor:"+HighlightColor[VHQt_M/2-1-j]+"','strokeWidth:0');\n";
                VHQt_Result+="for(var i=0; i<"+QString::number(3)+";i++) \n";
                VHQt_Result+="    {\n";
                VHQt_Result+="    "+NameChartLegend[VHQt_M/2-1-j]+"[1][i].setProperty({strokeColor:'"+Color[VHQt_M/2-1-j]+"',highlightStrokeColor:'"+HighlightColor[VHQt_M/2-1-j]+"',fillColor:'white',highlightFillColor:'white',face:'"+FaceOfLine[VHQt_M/2-1-j]+"', size:"+StrokeWidthPoints[VHQt_M/2-1-j]+", strokeWidth:'"+StrokeWidth[VHQt_M/2-1-j]+"pt'});\n";
                VHQt_Result+="    }\n";
            }
        }

        if (((!ShowPoints)&&(ShowLine))||((!ShowPoints)&&(!ShowLine)))
        {
            //Нарисуем только линию
            for (j=0;j<VHQt_M/2;j++)
            {
                VHQt_Result+="var "+NameChartLegend[VHQt_M/2-1-j]+"= "+NameBoardLegend+".createElement('chart', ["+NameDataXLegend+","+NameDataYLegend[VHQt_M/2-1-j]+"], {chartStyle:'line'});\n";
                VHQt_Result+=NameChartLegend[VHQt_M/2-1-j]+"[0].setProperty('strokeColor:"+Color[VHQt_M/2-1-j]+"','highlightStrokeColor:"+HighlightColor[VHQt_M/2-1-j]+"','strokeWidth:"+StrokeWidth[VHQt_M/2-1-j]+"');\n";
            }
        }

        //напишем текст
        QString Delim=";";
        for (j=0;j<VHQt_M/2;j++)
        {
            if (j==VHQt_M/2-1) Delim=".";
            VHQt_Result+=NameTextLegend[j]+" = "+NameBoardLegend+".create('text',[2.2,"+QString::number(VHQt_M/2-j)+", \"- "+NameLine[j]+Delim+"\"], {display:'internal', anchorX:'left',frozen: true, strokeColor:'#000000',highlightStrokeColor:'#000000'});\n";
        }

        VHQt_Result+="</script>\n";

        delete [] NameDataYLegend;
        delete [] NameChartLegend;
        delete [] NameTextLegend;
    }

    delete [] Color;
    delete [] HighlightColor;
    delete [] StrokeWidth;
    delete [] FaceOfLine;
    delete [] StrokeWidthPoints;
    delete [] ColorArea;
    delete [] OpacityArea;

    delete [] NameDataY;
    delete [] NameDataYArea;
    delete [] NameChart;
    delete [] SDataX;
    delete [] SDataY;

    for (i=0;i<VHQt_N_Max;i++) delete [] Temp_VHQt_MatrixXY[i];
    delete [] Temp_VHQt_MatrixXY;

    return VHQt_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_ShowIndependentChartsOfLineFromMatrix (T **VHQt_MatrixXY,int *VHQt_N_EveryCol,int VHQt_M, QString TitleChart, QString NameVectorX, QString NameVectorY,bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints)
{
    /*
Функция возвращает строку с выводом графиков из матрицы по точкам с HTML кодами. Для добавление в html файл.
Нечетные столбцы - это значения координат X графиков. Следующие за ними четные столбцы - соответствующие
значения Y. То есть графики друг от друга независимы.
Количество графиков равно половине столбцов в матрице.
Требует наличия в папке с html файлом файлы jsxgraph.css и jsxgraphcore.js из библиотеки JSXGraph.
Отличается от основной функции отсутствием легенды на графике.
Входные параметры:
 VHQt_MatrixXY - указатель на матрицу значений X и Н графиков;
 VHQt_N_EveryCol - количество элементов в каждом столбце (так как столбцы идут по парам, то число элементов в нечетном и
 следующем за ним четном столбце должны совпадать, например 10,10,5,5,7,7);
 VHQt_M - количество столбцов матрицы (должно быть четным числом конечно);
 TitleChart - заголовок графика;
 NameVectorX - название оси Ox;
 NameVectorY - название оси Oy;
 NameLine - указатель на вектор названий графиков (для легенды) количество элементов VHQt_M/2;
 ShowLine - показывать ли линию;
 ShowPoints - показывать ли точки;
 ShowArea - показывать ли закрашенную область под кривой;
 ShowSpecPoints - показывать ли специальные точки.
Возвращаемое значение:
 Строка с HTML кодами с выводимым графиком.
Примечание:
 Используются случайные числа, так что рекомендуется вызвать в программе инициализатор случайных чисел qsrand.
 Рекомендую так:
 qsrand(QDateTime::currentMSecsSinceEpoch () % 1000000);
*/
    QString VHQt_Result;//переменная итогового результата

    QString *NameLine=new QString[VHQt_M/2];
    for (int i=0;i<VHQt_M/2;i++) NameLine[i]="";

    VHQt_Result = THQt_ShowIndependentChartsOfLineFromMatrix (VHQt_MatrixXY,VHQt_N_EveryCol,VHQt_M,TitleChart, NameVectorX, NameVectorY,NameLine, ShowLine,ShowPoints, ShowArea,ShowSpecPoints);
    delete [] NameLine;

    return VHQt_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_ShowIndependentChartsOfLineFromMatrix (T **VHQt_MatrixXY,int *VHQt_N_EveryCol,int VHQt_M, QString TitleChart, QString NameVectorX, QString NameVectorY,QString *NameLine)
{
    /*
Функция возвращает строку с выводом графиков из матрицы по точкам с HTML кодами. Для добавление в html файл.
Нечетные столбцы - это значения координат X графиков. Следующие за ними четные столбцы - соответствующие
значения Y. То есть графики друг от друга независимы.
Количество графиков равно половине столбцов в матрице.
Требует наличия в папке с html файлом файлы jsxgraph.css и jsxgraphcore.js из библиотеки JSXGraph.
Отличается от основной функции отсутствием булевых переменных - все по умолчанию.
Входные параметры:
 VHQt_MatrixXY - указатель на матрицу значений X и Н графиков;
 VHQt_N_EveryCol - количество элементов в каждом столбце (так как столбцы идут по парам, то число элементов в нечетном и
 следующем за ним четном столбце должны совпадать, например 10,10,5,5,7,7);
 VHQt_M - количество столбцов матрицы (должно быть четным числом конечно);
 TitleChart - заголовок графика;
 NameVectorX - название оси Ox;
 NameVectorY - название оси Oy;
 NameLine - указатель на вектор названий графиков (для легенды) количество элементов VHQt_M/2.
Возвращаемое значение:
 Строка с HTML кодами с выводимым графиком.
Примечание:
 Используются случайные числа, так что рекомендуется вызвать в программе инициализатор случайных чисел qsrand.
 Рекомендую так:
 qsrand(QDateTime::currentMSecsSinceEpoch () % 1000000);
*/
    QString VHQt_Result;//переменная итогового результата

    VHQt_Result = THQt_ShowIndependentChartsOfLineFromMatrix (VHQt_MatrixXY,VHQt_N_EveryCol,VHQt_M,TitleChart, NameVectorX, NameVectorY,NameLine,  true,true, false,true);

    return VHQt_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_ShowIndependentChartsOfLineFromMatrix (T **VHQt_MatrixXY,int *VHQt_N_EveryCol,int VHQt_M)
{
    /*
Функция возвращает строку с выводом графиков из матрицы по точкам с HTML кодами. Для добавление в html файл.
Нечетные столбцы - это значения координат X графиков. Следующие за ними четные столбцы - соответствующие
значения Y. То есть графики друг от друга независимы.
Количество графиков равно половине столбцов в матрице.
Требует наличия в папке с html файлом файлы jsxgraph.css и jsxgraphcore.js из библиотеки JSXGraph.
Отличается от основной функции отсутствием булевых переменных, названий осей, графиков - все по умолчанию.
Входные параметры:
 VHQt_MatrixXY - указатель на матрицу значений X и Н графиков;
 VHQt_N_EveryCol - количество элементов в каждом столбце (так как столбцы идут по парам, то число элементов в нечетном и
 следующем за ним четном столбце должны совпадать, например 10,10,5,5,7,7);
 VHQt_M - количество столбцов матрицы (должно быть четным числом конечно);
 TitleChart - заголовок графика;
 NameVectorX - название оси Ox;
 NameVectorY - название оси Oy;
 NameLine - указатель на вектор названий графиков (для легенды) количество элементов VHQt_M/2.
Возвращаемое значение:
 Строка с HTML кодами с выводимым графиком.
Примечание:
 Используются случайные числа, так что рекомендуется вызвать в программе инициализатор случайных чисел qsrand.
 Рекомендую так:
 qsrand(QDateTime::currentMSecsSinceEpoch () % 1000000);
*/
    QString VHQt_Result;//переменная итогового результата

    QString *NameLine=new QString[VHQt_M/2];
    for (int i=0;i<VHQt_M/2;i++) NameLine[i]="";

    VHQt_Result = THQt_ShowIndependentChartsOfLineFromMatrix (VHQt_MatrixXY,VHQt_N_EveryCol,VHQt_M,"", "x", "y",NameLine, true,true, false,true);
    delete [] NameLine;

    return VHQt_Result;
}