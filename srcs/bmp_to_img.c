/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_to_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 15:16:23 by mmoullec          #+#    #+#             */
/*   Updated: 2016/09/28 15:50:25 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

typedef struct          s_bitmap
{
	short                       signature;
	int                         size;
	short                       reserved1;
	short                       reserved2;
	int                         dataoffSet;
	int                         bitmapheadersize;
	int                         width;
	int                         height;
	short                       planes;
	short                       bitsperpixel;
	int                         compression;
	int                         sizeImage;
	int                         xpixelspremeter;
	int                         ypixelspremeter;
	int                         colorsused;
	int                         colorsimportant;
}                                       t_bitmap;

typedef struct		s_pixel
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
}					t_pixel;

void *bmp_to_image(t_mlx *mlx, char *fn, int *w, int *h)
{
	int                             i;
	int                             j;
	int                             k;
	t_bitmap                source_info;
	t_pixel                 source_pix;
	unsigned char           *datas;

	FILE *fp;
	if(!(fp=fopen(fn,"rb")) || sizeof(source_info) != 54)
		return (NULL);
	memset(&source_info, 0, sizeof(source_info));
	fread(&source_info, sizeof(source_info), 1, fp);
	if (source_info.width < 0 || source_info.width > 2000 || source_info.height > 2000 || source_info.height < 0)
		return (NULL);
	fseek(fp, source_info.dataoffSet, SEEK_SET);
	datas = (unsigned char *)malloc(sizeof(unsigned char) * source_info.width * source_info.height * 3);
	i = 0;
	j = 0;
	k = 0;
	while (i < source_info.height)
	{
		k = 0;
		while (k < source_info.width)
		{
			fread(&source_pix, sizeof(t_pixel), 1, fp);
			datas[j++] = source_pix.r;
			datas[j++] = source_pix.g;
			datas[j++] = source_pix.b;
			k++;
		}
		if (k % 4 != 0)
			fread(NULL, k % 4, 1, fp);
		i++;
	}
	void *img = mlx_new_image(mlx->mlx, source_info.width, source_info.height);
	if (img)
	{
		char    *idatas;
		int             bpx;
		int             linesize;
		int             indian;
		idatas =  mlx_get_data_addr(img, &bpx, &linesize, &indian);
		i = 0;
		k = 0;
		while ((int)i < source_info.height)
		{
			j = 0;
			k = (source_info.height - 1 - i) * (source_info.width * 3);
			while ((int)j < source_info.width)
			{
				int index = i * linesize + ((j * bpx) >> 3);

				idatas[index] = datas[k++];
				idatas[++index] = datas[k++];
				idatas[++index] = datas[k++];
				j++;
			}
			i++;
		}
	}
	*h = source_info.height;
	*w = source_info.width;
//	free(datas);
	fclose(fp);
	return (img);
}
