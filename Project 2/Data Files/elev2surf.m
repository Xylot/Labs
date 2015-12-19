function elev2surf( input, fignum, end_az, end_el )
% Simple Matlab program to display an elevation file as a surface
%       Can display the Matlab sample files MountDartmouth-ft.grd and MtWashington-ft.grd, and the R sample file
%       volcano.nc (also found in tutorials as ex.nc)
%       Can read a PGM image and treat it as elevation data
%       Can also read ECE 1305's hybrid EGM files
%       Displays as colored surface with lighting, 
%       then spiral-rotates the surface, ending ad view [end_az, end_el]
%       
%   Inputs:
%       fname           input filename
%                           can also be a 2-D array of elevation
%       end_az, end_el  ending AZ & EL view, in degrees [0, 90]
%       fignum          figure # to use [next available]

            % default values if not provided
    if (~exist('end_az','var')), end_az = 0; end
    if (~exist('end_el','var')), end_el = 90; end
    if (~exist('fignum','var'))
        figure;
    else
        figure(fignum);
    end
    
            % get data, either from input or reading file specified in input
    if (~ischar(input))
        data = input;
    else
        fname = input;
        [~,~,fext] = fileparts(fname);      % get file extension to figure out how to read the data
        if (strcmp(fext,'.grd'))            % arcgis GRD files
            data = arcgridread(fname);
        elseif (strcmp(fext,'.nc'))         % netcdf files.  Will read 3rd variable as data
            data = read_ncfile(fname);      
        elseif (strcmp(fext,'.pgm'))        % PGM image
            data = imread(fname);
        elseif (strcmp(fext, '.egm'))       % EGM file
            data = egmread(fname);
        else
            throw(MException('ICSF:BAD_FILENAME',sprintf('error:  don''t know how to read ext %s:  %s', fext,fname)));
        end
    end
    print_summary(data);
    
    data = fixnans(data);                   % replace any missing data with min val in array
    colormap summer;                        % shades green to yellow.  Great for mountains!
    surf(data,'EdgeColor','none','SpecularExponent',25,'SpecularStrength',0.1);      % draw the surface
    [nr,nc] = size(data);                   % and fix the axis limits so they don't change while rotating.
    xlim([1,nc]);             
    ylim([1,nr]);
    
    rotate_surface(end_az, end_el);
    rotate3d on;

end

function print_summary(data)

    fprintf('Data summary: \n');
    fprintf(' array size:  %d x %d (rows, columns)\n', size(data));
    fprintf(' range:       %f to %f  (min, max)\n', nanmin(data(:)), nanmax(data(:)));
    fprintf(' mean, sdev:  %f  +/- %f\n', nanmean(data(:)), nanstd(data(:)));
    fprintf(' NaNs:        %d\n', sum(isnan(data(:))));
    
end

        % read 3rd variable from a netcdf file.  1st 2 s/b lat & lon., and data should be gridded.
function zdata = read_ncfile(fname)
    fprintf('reading variable 3 from netcdf file %s\n', fname);
    varid = 2;    % assume
    ncid = netcdf.open(fname);
    varname = netcdf.inqVar(ncid,varid);
    netcdf.close(ncid);
    zdata = ncread(fname,varname);
end

        % replace missing data with minimum found in dataset.
function data = fixnans(data)

    if (sum(isnan(data(:))) == 0), return; end
    data(isnan(data(:))) = nanmin(data(:)); 
end

% read text-based Elevation file (based on PGM file format)
function data = egmread(fname)
    % returns data array from file
    
    fprintf('reading EGM image %s\n', fname);

    fid = fopen(fname);
    if (fid == -1)
        throw(MException('ICSF:BAD_FILENAME',fprintf('error:  can''t open file for reading:  %s', fname)));
    end
        % read image type 
    ty = fscanf(fid,'%s',1);     % read image type ('E2')
    if (~strcmp(ty, 'E2'))
        throw(MException('ICSF:BAD_IMAGEFILE',sprintf('error:  file  %s not a E2 EGM image.  Hdr type is %s',fname, ty)));
    end
        % read image size, range & # of comments
    hdr_info=fscanf(fid,'%f',5);
    nc=hdr_info(1);
    nr=hdr_info(2);
    fprintf('header info:  size %d x %d , elevation range %f to %f\n', nc, nr, hdr_info(3), hdr_info(4));
    ncmnts=hdr_info(5);
        % skip over comments
    for i=1:(ncmnts+1)  
        s=fgetl(fid);
        if (i>1 && s(1) ~= '#')     % first one should be empty, reading to newline of current line in the file.
            throw(MException('ICSF:BAD_IMAGEFILE',sprintf('error:  reading file %s:  comment line does not begin with #: %s',fname, s)));
        end
        fprintf('comment: %s\n', s);        
    end
        % finally, read the data array
    data=fscanf(fid,'%f');
    if (length(data) ~= nc*nr)
        throw(MException('ICSF:BAD_IMAGEFILE',sprintf('error:  file size (%d) does not match header nc & nr:  %d x %d', length(data), nc, nr)));
    end
    fprintf(' data:  min %f  max %f  avg %f , std. deviation %f\n', nanmin(data), nanmax(data), mean(data), std(data));
    data=(reshape(data,nc,nr))';      % note:  data is read in row by row, so we reshape it then transpose it back to original shape.
end

        % rotates the view round to the ending az & el.
function rotate_surface(end_az, end_el)

    [a,e] = view;
    hlsky = light('Color',[.75,.75,1.0]);% light blue, for sky
    lightangle(hlsky, 45,70);           % put one light overhead, fixed position, to simulate sky
    
    hlsun = lightangle(a+45,60);  % add one light which will we'll keep in fixed position relative to camera view.
    end_az = mod(end_az, 360);
    end_el = mod(end_el, 180);
    if (end_az < a),       end_az = end_az + 360; end
    if (end_az - a < 180), end_az=end_az+360; end
    
    az = a:end_az;
    sunaz = az+45;
    skyaz = az-45;
    lel = 60;
    len = length(az);
    elstep = (end_el - e)/len;
    el = e:elstep:end_el;
    for i=1:len
        view(az(i),el(i));
        lightangle(hlsun, sunaz(i), lel);
        lightangle(hlsky, skyaz(i), 70);
        pause(.05);
    end
    view(end_az, end_el);
end
    