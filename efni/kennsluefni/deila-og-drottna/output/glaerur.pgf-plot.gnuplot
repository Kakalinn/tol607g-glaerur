set table "glaerur.pgf-plot.table"; set format "%.5f"
set samples 25; plot [x=-0.2:4.2] 0.9 + 1.08333*x - 0.75*x**2 + 0.166667*x**3
