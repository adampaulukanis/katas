(loop for i from 0 to 100
      do
      (let ((fizz (= (mod i 3) 0))
            (buzz (= (mod i 5) 0)))
        (princ i)
        (if (null fizz)
            (princ "    ")
            (princ "fizz"))
        (if (null buzz)
            (princ "    ")
            (princ "buzz"))
        (fresh-line)))
