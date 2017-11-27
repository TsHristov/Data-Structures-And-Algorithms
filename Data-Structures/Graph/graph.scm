(define (search p l)
  (and (not (null? l))
       (or (p (car l)) (search p (cdr l)))))

;; Sample graph:
(define graph '((1 2 3) (2 3 6) (3 4 6) (4 1 5) (5 3) (6 5)))

(define (make-graph g)
  (define (self prop . params)
    (case prop
      ('print g)
      ('vertices (map car graph))
      ('children (let ((v (car params)))
		   (cdr (assq v g))))
      ('edge? (let ((u (car params))
		    (v (cadr params)))
                (memq v (self 'children u))))
      ('map-children (let ((vertex (car params))
			   (f (cadr params)))
		       (map f (self 'children v))))
      ('search-child (let ((v (car params))
			   (f (cadr params)))
		       (search f (self 'children v))))))
  self)
