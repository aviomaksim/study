Public Class Form1
    Private _loend As Integer
    Private _img1 As String
    Private _img2 As String
    Private _img3 As String
    Private _imgMain As String
    Private _num As Integer
    Private _status As Boolean
    Private _winUni As String

    Public _form As Form



    Private Sub Button1_Click(sender As System.Object, e As System.EventArgs) Handles Button1.Click
        Button1.Enabled = False
        Button2.Enabled = True
        _status = False
        _loend = 60
        Timer1.Start()
    End Sub

    Private Sub Button2_Click(sender As System.Object, e As System.EventArgs) Handles Button2.Click
        Timer1.Stop()
        Button2.Enabled = False
        Dim t As String

        If _status Then
            t = "Saad aasta õppida " + _winUni + " ülikoolis!"
            MsgBox(t, 0, "VÕIT")
            Button3.Enabled = True
            Button3.Visible = True
        Else
            t = "Lasid käest võimaluse õppida " + _winUni + " ülikoolis!"
            MsgBox(t, 0, "EBAÕNN")
        End If
    End Sub

    Private Sub Timer1_Tick(sender As System.Object, e As System.EventArgs) Handles Timer1.Tick
        Dim rand As New Random
        Dim randNum1 As Integer
        Dim randNum2 As Integer
        Dim randNum3 As Integer

        Dim p As String

        Dim t As String
        If (_status And Not _winUni = "Stockgolm") Or _loend < 1 Then
            Timer1.Stop()
            Button2.Enabled = False
            t = "Lasid käest võimaluse õppida " + _winUni + " ülikoolis!"
            MsgBox(t, 0, "EBAÕNN")

        Else

            _loend -= 1
            Label1.Text = _loend

            randNum1 = rand.Next(3)
            If randNum1 > 1 Then
                p = _img1 + ".jpg"
                PictureBox1.Image = Image.FromFile(p)
                _winUni = "Oxford"
            ElseIf randNum1 < 1 Then
                p = _img2 + ".jpg"
                PictureBox1.Image = Image.FromFile(p)
                _winUni = "Harvard"
            Else
                p = _img3 + ".jpg"
                PictureBox1.Image = Image.FromFile(p)
                _winUni = "Stockgolm"
            End If

            randNum2 = rand.Next(3)
            If randNum2 > 1 Then
                p = _img1 + ".jpg"
                PictureBox2.Image = Image.FromFile(p)
            ElseIf randNum2 < 1 Then
                p = _img2 + ".jpg"
                PictureBox2.Image = Image.FromFile(p)
            Else
                p = _img3 + ".jpg"
                PictureBox2.Image = Image.FromFile(p)
            End If


            randNum3 = rand.Next(3)
            If randNum3 > 1 Then
                p = _img1 + ".jpg"
                PictureBox3.Image = Image.FromFile(p)
            ElseIf randNum3 < 1 Then
                p = _img2 + ".jpg"
                PictureBox3.Image = Image.FromFile(p)
            Else
                p = _img3 + ".jpg"
                PictureBox3.Image = Image.FromFile(p)
            End If

            If randNum1 = randNum2 And randNum1 = randNum3 Then
                _status = True
            Else
                _status = False
            End If


        End If
    End Sub

    Private Sub Form1_Load(sender As System.Object, e As System.EventArgs) Handles MyBase.Load
        _winUni = ""
        _num = 0
        _imgMain = "C:\Users\Maksim Kozorez\Documents\Visual Studio 2010\Projects\WindowsApplication6\WindowsApplication6\My Project\"
        _img1 = _imgMain + "OxfordUni"
        _img2 = _imgMain + "HarvardUni"
        _img3 = _imgMain + "StockholmUni"

        PictureBox1.Image = Image.FromFile(_img1 + ".jpg")
        PictureBox2.Image = Image.FromFile(_img2 + ".jpg")
        PictureBox3.Image = Image.FromFile(_img3 + ".jpg")

    End Sub

    Private Sub Button3_Click(sender As System.Object, e As System.EventArgs) Handles Button3.Click
        Dim map As New PictureBox
        
        _form = New Form()
        _form.Text = _winUni
        _form.Show()
        _form.BackColor = Color.Aqua
        Timer2.Interval = 1000
        Timer2.Start()

    End Sub

    Private Sub Timer2_Tick(sender As System.Object, e As System.EventArgs) Handles Timer2.Tick
        _num += 1
        If _num > 3 Then
            _num = 1
        End If

        Dim s As String
        s = _imgMain + _winUni + ".jpg"

        _form.BackgroundImageLayout = ImageLayout.Stretch
        _form.BackgroundImage = Image.FromFile(s)

    End Sub
End Class
