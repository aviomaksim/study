<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class Form1
    Inherits System.Windows.Forms.Form

    'Form overrides dispose to clean up the component list.
    <System.Diagnostics.DebuggerNonUserCode()> _
    Protected Overrides Sub Dispose(ByVal disposing As Boolean)
        Try
            If disposing AndAlso components IsNot Nothing Then
                components.Dispose()
            End If
        Finally
            MyBase.Dispose(disposing)
        End Try
    End Sub

    'Required by the Windows Form Designer
    Private components As System.ComponentModel.IContainer

    'NOTE: The following procedure is required by the Windows Form Designer
    'It can be modified using the Windows Form Designer.  
    'Do not modify it using the code editor.
    <System.Diagnostics.DebuggerStepThrough()> _
    Private Sub InitializeComponent()
        Me.ShapeContainer1 = New Microsoft.VisualBasic.PowerPacks.ShapeContainer()
        Me.LineShape1 = New Microsoft.VisualBasic.PowerPacks.LineShape()
        Me.LineShape2 = New Microsoft.VisualBasic.PowerPacks.LineShape()
        Me.LineShape3 = New Microsoft.VisualBasic.PowerPacks.LineShape()
        Me.Rect1 = New Microsoft.VisualBasic.PowerPacks.RectangleShape()
        Me.Rect2 = New Microsoft.VisualBasic.PowerPacks.RectangleShape()
        Me.Rect3 = New Microsoft.VisualBasic.PowerPacks.RectangleShape()
        Me.Button1 = New System.Windows.Forms.Button()
        Me.SuspendLayout()
        '
        'ShapeContainer1
        '
        Me.ShapeContainer1.Location = New System.Drawing.Point(0, 0)
        Me.ShapeContainer1.Margin = New System.Windows.Forms.Padding(0)
        Me.ShapeContainer1.Name = "ShapeContainer1"
        Me.ShapeContainer1.Shapes.AddRange(New Microsoft.VisualBasic.PowerPacks.Shape() {Me.Rect3, Me.Rect2, Me.Rect1, Me.LineShape3, Me.LineShape2, Me.LineShape1})
        Me.ShapeContainer1.Size = New System.Drawing.Size(284, 262)
        Me.ShapeContainer1.TabIndex = 0
        Me.ShapeContainer1.TabStop = False
        '
        'LineShape1
        '
        Me.LineShape1.Name = "LineShape1"
        Me.LineShape1.X1 = 40
        Me.LineShape1.X2 = 40
        Me.LineShape1.Y1 = 40
        Me.LineShape1.Y2 = 200
        '
        'LineShape2
        '
        Me.LineShape2.Name = "LineShape2"
        Me.LineShape2.X1 = 120
        Me.LineShape2.X2 = 120
        Me.LineShape2.Y1 = 40
        Me.LineShape2.Y2 = 200
        '
        'LineShape3
        '
        Me.LineShape3.Name = "LineShape3"
        Me.LineShape3.X1 = 200
        Me.LineShape3.X2 = 200
        Me.LineShape3.Y1 = 40
        Me.LineShape3.Y2 = 200
        '
        'Rect1
        '
        Me.Rect1.BackColor = System.Drawing.Color.Red
        Me.Rect1.BackStyle = Microsoft.VisualBasic.PowerPacks.BackStyle.Opaque
        Me.Rect1.Location = New System.Drawing.Point(40, 155)
        Me.Rect1.Name = "Rect1"
        Me.Rect1.Size = New System.Drawing.Size(60, 45)
        '
        'Rect2
        '
        Me.Rect2.BackColor = System.Drawing.Color.Blue
        Me.Rect2.BackStyle = Microsoft.VisualBasic.PowerPacks.BackStyle.Opaque
        Me.Rect2.Location = New System.Drawing.Point(120, 155)
        Me.Rect2.Name = "Rect2"
        Me.Rect2.Size = New System.Drawing.Size(60, 45)
        '
        'Rect3
        '
        Me.Rect3.BackColor = System.Drawing.Color.Yellow
        Me.Rect3.BackStyle = Microsoft.VisualBasic.PowerPacks.BackStyle.Opaque
        Me.Rect3.Location = New System.Drawing.Point(200, 155)
        Me.Rect3.Name = "Rect3"
        Me.Rect3.Size = New System.Drawing.Size(60, 45)
        '
        'Button1
        '
        Me.Button1.Location = New System.Drawing.Point(107, 218)
        Me.Button1.Name = "Button1"
        Me.Button1.Size = New System.Drawing.Size(75, 23)
        Me.Button1.TabIndex = 1
        Me.Button1.Text = "HEISATA"
        Me.Button1.UseVisualStyleBackColor = True
        '
        'Form1
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(284, 262)
        Me.Controls.Add(Me.Button1)
        Me.Controls.Add(Me.ShapeContainer1)
        Me.Name = "Form1"
        Me.Text = "Form1"
        Me.ResumeLayout(False)

    End Sub
    Friend WithEvents ShapeContainer1 As Microsoft.VisualBasic.PowerPacks.ShapeContainer
    Friend WithEvents LineShape1 As Microsoft.VisualBasic.PowerPacks.LineShape
    Friend WithEvents Rect1 As Microsoft.VisualBasic.PowerPacks.RectangleShape
    Friend WithEvents LineShape3 As Microsoft.VisualBasic.PowerPacks.LineShape
    Friend WithEvents LineShape2 As Microsoft.VisualBasic.PowerPacks.LineShape
    Friend WithEvents Rect3 As Microsoft.VisualBasic.PowerPacks.RectangleShape
    Friend WithEvents Rect2 As Microsoft.VisualBasic.PowerPacks.RectangleShape
    Friend WithEvents Button1 As System.Windows.Forms.Button

End Class
