Public Class Form1
    Private PraeguneTem As Double
    Private MinTem As Double
    Private MaxTem As Double
    Private KiirusJahe As Double
    Private KiirusTouse As Double
    Private KasRadiaatorSees As Boolean
    Private KasTVSees As Boolean
    Private KasValgusSees As Boolean

    Private VooluVoimsus As Double
    Private RadiaatoriVoimsus As Double
    Private TVVoimsus As Double
    Private ValgusVoimsus As Double

    Private Sub Form1_Load(ByVal sender As System.Object, _
    ByVal e As System.EventArgs) Handles MyBase.Load
        'default
        PraeguneTem = 10
        KiirusJahe = 0.3
        KiirusTouse = 0.1
        KasRadiaatorSees = False
        VooluVoimsus = 0
        KasTVSees = False
        KasValgusSees = False
        RadiaatoriVoimsus = 1000
        TVVoimsus = 60
        ValgusVoimsus = 15

        MinTem = TemSisse.Text
        MaxTem = TemValja.Text

        Timer1.Start()
    End Sub

    Private Sub Timer1_Tick(sender As System.Object, e As System.EventArgs) Handles Timer1.Tick
        VooluVoimsus = 0

        If PraeguneTem < MinTem Then
            KasRadiaatorSees = True
        ElseIf PraeguneTem > MaxTem Then
            KasRadiaatorSees = False
        End If

        If KasRadiaatorSees Then
            Status.Text = "Radiaator sees"
            StatusOval.BackColor = Color.Green
            PraeguneTem += KiirusTouse
            VooluVoimsus += RadiaatoriVoimsus
        Else
            Status.Text = "Radiaator välja"
            StatusOval.BackColor = Color.Red
            PraeguneTem -= KiirusJahe
        End If

        If KasValgusSees Then
            Valgus.BackColor = Color.Yellow
            VooluVoimsus += ValgusVoimsus
        Else
            Valgus.BackColor = Color.Gray
        End If

        If KasTVSees Then
            TV.BackColor = Color.Blue
            VooluVoimsus += TVVoimsus
        Else
            TV.BackColor = Color.Gray
        End If

        TemPraegu.Text = Format(PraeguneTem, "00.0")
        VooluPraegu.Text = VooluVoimsus
        Termometr.Y1 = Termometr.Y2 - PraeguneTem
    End Sub

    Private Sub Label4_Click(sender As System.Object, e As System.EventArgs) Handles Status.Click

    End Sub

    Private Sub TemSisse_TextChanged(sender As System.Object, e As System.EventArgs) Handles TemSisse.TextChanged
        If Not IsNumeric(TemSisse.Text) Then
            TemSisse.Text = MinTem
        Else
            MinTem = TemSisse.Text
        End If
    End Sub

    Private Sub TemValja_TextChanged(sender As System.Object, e As System.EventArgs) Handles TemValja.TextChanged
        If Not IsNumeric(TemValja.Text) Then
            TemValja.Text = MaxTem
        Else
            MaxTem = TemValja.Text
        End If
    End Sub

    Private Sub ValgusLuliti_Click(sender As System.Object, e As System.EventArgs) Handles ValgusLuliti.Click
        If KasValgusSees Then
            KasValgusSees = False
        Else
            KasValgusSees = True
        End If
    End Sub

    Private Sub TVLuliti_Click(sender As System.Object, e As System.EventArgs) Handles TVLuliti.Click
        If KasTVSees Then
            KasTVSees = False
        Else
            KasTVSees = True
        End If
    End Sub
End Class
