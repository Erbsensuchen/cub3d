/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 15:51:09 by lseeger           #+#    #+#             */
/*   Updated: 2025/06/20 15:47:40 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static bool	filename_valid(const char *scene_path)
{
	int	len;

	if (scene_path == NULL)
		return (false);
	len = ft_strlen(scene_path);
	if (len < 5)
		return (false);
	if (ft_strncmp(scene_path + len - 4, ".cub", 4) != 0)
		return (false);
	return (true);
}

bool	scene_valid(const char *scene_path)
{
	int	fd;

	if (!filename_valid(scene_path))
		return (print_parsing_error("Files need to End with .cub!\n"), false);
	fd = open(scene_path, O_RDONLY);
	if (fd < 0)
		return (print_parsing_error("Error when Opening File!\n"), false);
	return (close(fd), true);
}
