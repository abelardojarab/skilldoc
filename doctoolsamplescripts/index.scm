(load (string-append laml-dir "laml.scm"))
(laml-style "xml-in-laml/schemedoc-index/schemedoc-index")

(manual-index
 (manual-index-front-matters
  (manual-index-title "FRAT API Manual Index")
  'browser-type "one-step"     ; one-step or two-steps
  'left-frame-width "250px"
  'top-frame-height "200px"
  'initial-manual-frame "first-manual-contribution"
  'source-destination-delta ""
  'scheme-report "none"       ; none, include, merge
  )

 ;; Indexing region
 (manual-index-contributions
  (manual-index-contribution
   'informative-name "layout1func"
   'path "layout1func.manlsp")
  (manual-index-contribution
   'informative-name "layout2func"
   'path "layout2func.manlsp")
  (manual-index-contribution
   'informative-name "layout3func"
   'path "layout3func.manlsp")
  (manual-index-contribution
   'informative-name "layout4func"
   'path "layout4func.manlsp")
  (manual-index-contribution
   'informative-name "layout5func"
   'path "layout5func.manlsp")
  (manual-index-contribution
   'informative-name "layout6func"
   'path "layout6func.manlsp")
  (manual-index-contribution
   'informative-name "mathfunc"
   'path "mathfunc.manlsp")
  ) ;; contributions

 )
