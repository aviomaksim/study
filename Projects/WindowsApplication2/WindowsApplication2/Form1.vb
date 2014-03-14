Public Class Form1
    Public AegAlg As Date
    Public AegStopper As Date

    Private Sub Form1_Load(ByVal sender As System.Object, _
    ByVal e As System.EventArgs) Handles MyBase.Load
        Kell1.Text = TimeSerial(0, 0, 0)
        Kell2.Text = TimeSerial(0, 0, 0)
        Kell3.Text = TimeSerial(0, 0, 0)

        AegAlg = TimeOfDay
        Timer1.Start()
    End Sub

    Private Sub Timer1_Tick(sender As System.Object, e As System.EventArgs) Handles Timer1.Tick
        Dim Aeg As Date
        Aeg = TimeOfDay
        Kell1.Text = Hour(Aeg) & ":" & Format(Minute(Aeg), "00") & ":" & Format(Second(Aeg), "00")
        Kell2.Text = TimeSerial(DateDiff(DateInterval.Hour, AegAlg, Aeg), DateDiff(DateInterval.Minute, AegAlg, Aeg), DateDiff(DateInterval.Second, AegAlg, Aeg))
    End Sub

    Private Sub Button1_Click(sender As System.Object, e As System.EventArgs) Handles Button1.Click
        AegStopper = TimeOfDay
        Timer2.Start()
    End Sub

    Private Sub Button2_Click(sender As System.Object, e As System.EventArgs) Handles Button2.Click
        Timer2.Stop()
    End Sub

    Private Sub Button3_Click(sender As System.Object, e As System.EventArgs) Handles Button3.Click
        AegStopper = TimeOfDay
        Kell3.Text = TimeSerial(0, 0, 0)
    End Sub

    Private Sub Timer2_Tick(sender As System.Object, e As System.EventArgs) Handles Timer2.Tick
        Dim Aeg As DateTime
        Aeg = TimeOfDay
        Kell3.Text = TimeSerial(DateDiff(DateInterval.Hour, AegStopper, Aeg), DateDiff(DateInterval.Minute, AegStopper, Aeg), DateDiff(DateInterval.Second, AegStopper, Aeg))
    End Sub
End Class
