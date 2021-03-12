void suffix_array(char* s, int n, int* p)
{
	s[n] = ' ' - 1, s[n + 1] = '\0'; n++;
    int i, k = 1, a = 256, h;
	int c[n], g[a], gg[n], pn[n], cn[n];
	rep(i, a) g[i] = 0;
	rep(i, n) g[s[i]]++;
	rep(i, a) if (i != 0) g[i] += g[i-1];
	rep(i, n) p[--g[s[i]]] = i;
    c[p[0]] = 0;
	rep(i, n) if (i != 0) c[p[i]] = (s[p[i]] != s[p[i - 1]] ? ++k : k) - 1;
    for (h = 0; (1 << h) < n; ++h)
	{
		rep(i, n) pn[i] = p[i] - (1 << h), pn[i] += pn[i] < 0 ? n : 0;
		rep(i, k) gg[i] = 0;
		rep(i, n) gg[c[pn[i]]]++;
		rep(i, k) if (i != 0) gg[i] += gg[i-1];
		rep(i, n) p[--gg[c[pn[n - 1 - i]]]] = pn[n - 1 - i];
        cn[p[0]] = 0;
        k = 1;
		rep(i, n) if (i != 0) cn[p[i]] =
			(c[p[i]] != c[p[i - 1]] ||
			 c[(p[i] + (1 << h)) % n] !=
			 	c[(p[i - 1] + (1 << h)) % n] ? ++k : k) - 1;
		rep(i, n) c[i] = cn[i];
    }
	rep(i, n - 1) p[i] = p[i + 1];
}
