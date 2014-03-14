Public Class Form1
    Public AegAlg As Date
    Public Sund As Boolean


    Private Sub Form1_Load(ByVal sender As System.Object, _
    ByVal e As System.EventArgs) Handles MyBase.Load
        AegAlg = TimeOfDay
        Sund = False
        Timer1.Start()

    End Sub

    Private Sub Timer1_Tick(sender As System.Object, e As System.EventArgs) Handles Timer1.Tick
        Dim Aeg As Date
        Aeg = TimeOfDay
        Dim AegDiff As Long = DateDiff(DateInterval.Second, AegAlg, Aeg)

        If Label3.Visible And Label4.Visible Then
            Label3.Visible = False
            Label4.Visible = True
            Label5.Visible = True
            Label6.Visible = False
            Label7.Visible = False
            Label03.Visible = False
            Label04.Visible = True
            Label05.Visible = True
            Label06.Visible = False
            Label07.Visible = False
        ElseIf Label4.Visible And Label5.Visible Then
            Label3.Visible = False
            Label4.Visible = False
            Label5.Visible = True
            Label6.Visible = True
            Label7.Visible = False
            Label03.Visible = False
            Label04.Visible = False
            Label05.Visible = True
            Label06.Visible = True
            Label07.Visible = False
        ElseIf Label5.Visible And Label6.Visible Then
            Label3.Visible = False
            Label4.Visible = False
            Label5.Visible = False
            Label6.Visible = True
            Label7.Visible = True
            Label03.Visible = False
            Label04.Visible = False
            Label05.Visible = False
            Label06.Visible = True
            Label07.Visible = True
        ElseIf Label6.Visible And Label7.Visible Then
            Label3.Visible = False
            Label4.Visible = False
            Label5.Visible = False
            Label6.Visible = False
            Label7.Visible = True
            Label03.Visible = False
            Label04.Visible = False
            Label05.Visible = False
            Label06.Visible = False
            Label07.Visible = True
        ElseIf Label7.Visible Then
            Label3.Visible = True
            Label4.Visible = False
            Label5.Visible = False
            Label6.Visible = False
            Label7.Visible = False
            Label03.Visible = True
            Label04.Visible = False
            Label05.Visible = False
            Label06.Visible = False
            Label07.Visible = False
        ElseIf Label3.Visible Then
            Label3.Visible = True
            Label4.Visible = True
            Label5.Visible = False
            Label6.Visible = False
            Label7.Visible = False
            Label03.Visible = True
            Label04.Visible = True
            Label05.Visible = False
            Label06.Visible = False
            Label07.Visible = False
        Else

        End If

        If AegDiff < 2 Then
            Label1.BackColor = Color.AntiqueWhite
            Label1.ForeColor = Color.Chocolate
        ElseIf AegDiff < 4 Then
            Label1.BackColor = Color.Aquamarine
            Label1.ForeColor = Color.Black
        ElseIf AegDiff < 6 Then
            Label1.BackColor = Color.BlanchedAlmond
            Label1.ForeColor = Color.Chocolate
        ElseIf AegDiff < 8 Then
            Label1.BackColor = Color.RosyBrown
            Label1.ForeColor = Color.Black
        ElseIf AegDiff < 10 Then
            AegAlg = TimeOfDay
        End If

        If Label2.Location.X > 98 Then
            Sund = False
        ElseIf Label2.Location.X < 28 Then
            Sund = True
        End If

        If Sund Then
            Label2.Location = New Point(Label2.Location.X + 3, Label2.Location.Y)
        Else
            Label2.Location = New Point(Label2.Location.X - 3, Label2.Location.Y)
        End If




    End Sub

    Private Sub OvalShape1_Click(sender As System.Object, e As System.EventArgs) Handles OvalShape1.Click

    End Sub
End Class
